#include <stdio.h>
#include <stdlib.h>
typedef struct arb
{
    int val,occ;// Valeur du nœud et nombre d'occurrences.
    struct arb* fd;// Pointeur vers le fils droit.
    struct arb* fg;// Pointeur vers le fils gauche.
} pArbre;

pArbre* CreerArbre(int nv)
{
    pArbre* R = (pArbre*)malloc(sizeof(pArbre));
    if (!R)
    {
        printf("Erreur de mémoire\n");
        exit(-1);
    }
    R->val = nv;//Initialise la valeur du nœud.
    R->occ = 1; // Initialise le nombre d'occurrences à 1.
    R->fg = R->fd = NULL;// Initialise les pointeurs enfants à NULL.

    return R;//Retourne le nœud créé.
}

/// Vérifie si un nœud est une feuille (n'a pas d'enfants).
int estfeuille(pArbre* R)
{
    if (!R->fd && !R->fg)
        return 1;// Renvoie 1 si le nœud est une feuille.
    return 0;  //Renvoie 0 sinon.
}
///Fonction pour inserer une valeur par recursion
pArbre* inserer_arb_rec(pArbre* R, int v)
{
    if (!R)
        return CreerArbre(v);//Crée un nœud si l'arbre est vide.

    //Insère l'élément à droite de la racine si v > R->val.
    if (v > R->val)
        R->fd = inserer_arb_rec(R->fd, v);
    //Insère l'élément à gauche de la racine si v < R->val.
    else if (v < R->val)
        R->fg = inserer_arb_rec(R->fg, v);
    else
        R->occ++;//Incrémente le nombre d'occurrences si la valeur existe déjà.

    return R;//Renvoie l'arbre mis à jour.
}

/// Affiche l'arbre en ordre infixé.
void afficherInfixe(pArbre* R)
{
    if (R)
    {
        afficherInfixe(R->fg);// Parcours le sous-arbre gauche.
        printf("[%d, occ=%d]", R->val, R->occ);
        afficherInfixe(R->fd);// Parcours le sous-arbre droit.
    }
}

/// Affiche l'arbre en ordre préfixé.
void afficherPrefixe(pArbre* R)
{
    if (R)
    {
        printf("[%d, occ=%d]", R->val, R->occ);
        afficherPrefixe(R->fg);//Parcours le sous-arbre gauche en préfixe.
        afficherPrefixe(R->fd);//Parcours le sous-arbre droit en préfixe.
    }
}

///Affiche l'arbre en ordre postfixé.
void afficherPostfixe(pArbre* R)
{
    if (R)
    {
        afficherPostfixe(R->fd);//Parcours le sous-arbre droit en postfixe.
        afficherPostfixe(R->fg);//Parcours le sous-arbre gauche en postfixe.
        printf("[%d, occ=%d]", R->val, R->occ);
    }
}

///Affiche l'arbre horizontalement.
void Aff_Arbre_horiz(pArbre* Arbre, int Niv)
{
    int esp;  // Pour l'affichage des espaces.
    if (Arbre)  // Condition d'arrêt.
    {   // Affiche les fils droits.
        Aff_Arbre_horiz(Arbre->fd, Niv + 1);
        printf("\n");
        for (esp = 0; esp < Niv; esp++)
            printf("\t");
        printf("%d", Arbre->val);  // Affiche la valeur du nœud.
        // Affiche les fils gauches.
        Aff_Arbre_horiz(Arbre->fg, Niv + 1);
    }
}

///Calcule la taille de l'arbre (nombre de nœuds).
int Taille_Arb(pArbre* R)
{
    if (!R)
        return 0;
    return 1 + Taille_Arb(R->fd) + Taille_Arb(R->fg);
}

///Recherche un élément dans l'arbre.
int rechercher(pArbre* R, int elem)
{
    if (R)
    {
        if (R->val == elem)
            return 1;//Renvoie 1 si la valeur est trouvée.
        else if (elem > R->val)
            return rechercher(R->fd, elem);//Recherche dans le sous-arbre droit.
        else
            return rechercher(R->fg, elem);//Recherche dans le sous-arbre gauche.
    }
    return 0;//Renvoie 0 si la valeur n'est pas trouvée.

}

///Trouve le nœud avec la valeur maximale dans l'arbre.
pArbre* maxArb(pArbre* R)
{
    if (!R->fd)
        return R;
    else
        return maxArb(R->fd);//Continue de chercher dans le sous-arbre droit.
}

///Trouve le nœud avec la valeur minimale dans l'arbre.
pArbre* minArb(pArbre* R)
{
    if (!R->fg)
        return R;
    else
        return minArb(R->fg);//Continue de chercher dans le sous-arbre gauche.
}

///Calcule la hauteur de l'arbre.
int hauteur(pArbre* R)
{
    int maxG=0, maxD=0;
    if (!R)
        return 0;
    else
    {
        maxG +=1+hauteur(R->fg);//Calcule la hauteur du sous-arbre gauche.
        maxD +=1+hauteur(R->fd);//Calcule la hauteur du sous-arbre droit.
        if (maxD >= maxG)
            return (int)maxD;//Renvoie la hauteur maximale.
        return (int) maxG;//Renvoie la hauteur maximale.
    }
}

///Fonction de suppression d'un element
pArbre* supprimer_arb(pArbre* R, int X)
{
    if (!R)
        return R;/// Cas : L'arbre est vide ou la valeur n'est pas trouvée.

    if (X < R->val)
        R->fg = supprimer_arb(R->fg, X);
    else if (X > R->val)
        R->fd = supprimer_arb(R->fd, X);
    else
    {
        /// Cas : Le nœud actuel contient la valeur à supprimer.
        pArbre* temp = R;
        if (!R->fg && !R->fd)
        {
            /// Cas : Le nœud est une feuille (n'a pas d'enfants).
            free(R);  // Libère la mémoire occupée par le nœud.
            R = NULL;  // Définit le nœud actuel à NULL.
        }
        else if (!R->fg)
        {
            /// Cas : Le nœud a seulement un enfant droit.
           R = R->fd; // Met à jour le nœud actuel pour pointer vers l'enfant droit.
            free(temp); // Libère la mémoire du nœud original.
        }
        else if (!R->fd)
        {
            /// Cas : Le nœud a seulement un enfant gauche.
            R = R->fg; // Met à jour le nœud actuel pour pointer vers l'enfant gauche.
            free(temp); // Libère la mémoire du nœud original.

        }
        else
        {
            /// Cas : Le nœud a à la fois des enfants gauche et droit.
            temp = minArb(R->fd);// Trouve le nœud de valeur minimale dans le sous-arbre droit.
            // Copie la valeur du nœud minimal dans le nœud actuel.
            R->val = temp->val;
            //Supprime le nœud minimal récursivement du sous-arbre droit.
            R->fd = supprimer_arb(R->fd, temp->val);
        }
    }
    return R;
}
///Fonction : Insertion iterative
void inserer_arb_ite(pArbre** R,int v)
{
    pArbre* NE=CreerArbre(v),*temp;
    if(!*R)
    {
        *R=NE;
         return;
    }
    temp=*R;
    while(1)
    {
        if(v > temp->val)
        {
           if(!temp->fd)
           {
             temp->fd=NE;
             break;
           }
           temp=temp->fd;
        }
        else if(v < temp->val)
        {
           if(!temp->fg)
           {
             temp->fg=NE;
             break;
           }
           temp=temp->fg;
        }
        else
        {
          temp->occ++;
          break;
        }
    }
}
void Vider_arb(pArbre** R)
{
    if (*R)
    {
        printf("\nSuppression de : %d", (*R)->val);//Affiche la valeur du nœud à supprimer.
        Vider_arb(&(*R)->fg);//Récursivement supprime le sous-arbre gauche.
        Vider_arb(&(*R)->fd);//Récursivement supprime le sous-arbre droit.
        free(*R);//Libère la mémoire du nœud actuel.
        *R = NULL;//Réinitialise le pointeur pour éviter les accès non valides.
    }
}
///Fonction pour calculer la somme des elememts
int SommeArb(pArbre* R)
{
    int S = 0; //Initialise la somme à zéro.

    if (!R)
    {
        return S;
    }
    else
    {
        S += R->val;//Ajoute la valeur du nœud actuel à la somme.
        // Ajoute récursivement la somme des sous-arbres gauche et droit.
        S += SommeArb(R->fg);
        S += SommeArb(R->fd);
        return S; // Retourne la somme totale.
    }
}


int main()
{

pArbre *T=NULL;
T=inserer_arb_rec(T,1);
T=inserer_arb_rec(T,2);
T=inserer_arb_rec(T,3);
T=inserer_arb_rec(T,4);
T=inserer_arb_rec(T,7);
T=inserer_arb_rec(T,6);
T=inserer_arb_rec(T,5);
T=inserer_arb_rec(T,8);
T=inserer_arb_rec(T,9);
T=inserer_arb_rec(T,10);
T=inserer_arb_rec(T,11);
T=inserer_arb_rec(T,12);
T=inserer_arb_rec(T,13);
T=inserer_arb_rec(T,14);T=inserer_arb_rec(T,15);
T=inserer_arb_rec(T,16);
T=inserer_arb_rec(T,17);
T=inserer_arb_rec(T,18);
T=inserer_arb_rec(T,19);
T=inserer_arb_rec(T,20);
T=inserer_arb_rec(T,21);
T=inserer_arb_rec(T,22);
T=inserer_arb_rec(T,123);
T=inserer_arb_rec(T,124);
T=inserer_arb_rec(T,122);
afficherInfixe(T);







    return 0;
}
