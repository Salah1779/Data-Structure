#include <stdio.h>
#include <stdlib.h>
#define Max 100

typedef struct T
{
    int T[Max],nbElem;

}Table;
/*
void init_Tab(Table*t)
{
  t->nbElem=0;
}*/
void inserer_Tab(Table*t, int e)
{
    if(t->nbElem==Max)
    {
        printf("\nLe tableau est sature.");
        exit(-1);
    }
    else
    {
        t->T[t->nbElem]=e;
        t->nbElem++;
    }
}
void echange(int *a,int *b)
{
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;

}
void afficher_tab(Table t)
{
    if(t.nbElem==0) printf("\nLe tableau est vide");
    else
       for(int i=0;i<t.nbElem; i++)
         printf("%d  ",t.T[i]);
    printf("\n");
}
// Tri à bulles sur la table
void Trie_Bulle_Tab(Table* t)
{
    int trie, len = t->nbElem, i;
    do {
         trie = 1;
         for (i = 0; i < len-1; i++)
         {
            // Comparaison et échange si nécessaire
            if (t->T[i] > t->T[i+1])
            {
                echange(&t->T[i], &t->T[i+1]);
                trie = 0;  // Indique qu'il y a eu un échange
                afficher_tab(*t); // Affiche l'état actuel de la table
            }
         }
        len--;
      } while (trie == 0);  // Continue tant qu'il y a des échanges à faire
}

// Tri par sélection sur la table
void Tri_selection_Tab(Table* t)
{
    int i, j, i_min;
    for (i=0; i < t->nbElem-1; i++)
    {
        i_min = i;
        // Recherche de l'indice du minimum dans la portion non triée
        for (j=i+1; j < t->nbElem; j++)
            if (t->T[j] < t->T[i_min])
                i_min = j;
        // Échange si l'indice du minimum a changé
        if (i != i_min)
        {
            echange(&t->T[i], &t->T[i_min]);
            afficher_tab(*t);
        }
    }
}

// Tri par insertion sur la table
void Trie_insertion_Tab(Table* t)
{
    int cle, i, j;
    for (i=1; i < t->nbElem; i++)
    {
        cle =t->T[i];
        j = i-1;
        // Déplacement des éléments plus grands que la clé
        while ((j >= 0) && (t->T[j] > cle))
        {
            t->T[j+1] = t->T[j];
            j = j-1;
            t->T[j+1] = cle;
        }
        afficher_tab(*t);  // Affiche l'état actuel de la table
    }
}

int partition_Tab(Table* t, int debut, int fin)
{
    // Sélectionne le dernier élément comme pivot
    int pivot=t->T[fin];
    // Initialise l'indice de l'élément plus petit que le pivot à gauche du tableau
    int gauche=debut-1;

    // Parcourt tous les éléments du tableau sauf le pivot
    for (int j=debut; j<fin; j++)
    {
        // Déplacement des éléments inférieurs ou égaux au pivot à gauche
        if (t->T[j] < pivot)
        {
            gauche++;//Incrémente l'indice gauche car un élément inférieur ou égal au pivot a été trouvé.
            // Échange l'élément actuel avec l'élément à l'indice gauche
            echange(&(t->T[j]), &(t->T[gauche]));
        }
    }
    // Échange le pivot avec l'élément à la position correcte
    echange(&(t->T[gauche+1]), &(t->T[fin]));
    // Retourne l'indice du pivot après le partitionnement
    return gauche + 1;
}

void Tri_rapide_Tab(Table* t,int debut,int fin)
{
  if(debut<fin)
  {
      int p=partition_Tab(t,debut,fin);
      afficher_tab(*t);
      Tri_rapide_Tab(t,p+1,fin);
      Tri_rapide_Tab(t,debut,p-1);
  }

}


// Ttraitement avec pointeur
typedef struct L
{
    int val;
    struct L* svt,*pred;
}Liste;

Liste *CreerListe(int val)
{
    Liste* cel=(Liste*)malloc(sizeof(Liste));
    if(cel)
    {
        cel->val=val;
        cel->svt=cel->pred=NULL;
    }
    return cel;
}

Liste* dernier(Liste* L)
{
    Liste* der;
    for(der=L;der->svt;der=der->svt);
    return der;
}
Liste *inserer_liste(Liste*L,int e)
{
    Liste* NE=CreerListe(e);
    if(L)
    {
        NE->svt=L;
        L->pred=NE;
        L=NE;
    }else L=NE;
    return L;
}
int Taille(Liste *L)
{
  if(!L) return 0;
  return 1+Taille(L->svt);
}

void afficher_liste(Liste *L)
{
    Liste* courant;
    if(!L)
        printf("\nLa liste est vide.");
    else
       for(courant=L; courant ; courant=courant->svt)
          printf("%d  ",courant->val);

    printf("\n");
}

void Trie_Bulle_Liste(Liste* L)
{
    int trie;
    Liste*courant,*der=dernier(L);
    do
    {
         trie=1;
        for(courant=L;courant!=der;courant=courant->svt)
        {
          if(courant->val > courant->svt->val )
            {
                echange(&(courant->val),&(courant->svt->val));
                trie=0;
                afficher_liste(L);
            }
        }
        der=der->pred;
    }while(trie==0);
}

void Tri_selection_Liste (Liste *L)
{
   Liste *min, *courant1, *courant2 ;
   for(courant1=L; courant1->svt ;courant1=courant1->svt)
   {
      min=courant1;
      for(courant2=courant1->svt; courant2 ;courant2=courant2->svt)
          if(courant2->val < min->val)
             min=courant2;
      if(courant1!=min)
      {
        echange(&(courant1->val),&(min->val));
        afficher_liste(L);
      }
   }
}

 void TrieInsertion_Liste(Liste *L)
{

    Liste *cle,*courant;

    for(courant=L->svt; courant ;courant=courant->svt)
    {
        cle=courant;
        while((cle->pred) && (cle->pred->val > cle->val))
        {
           echange(&(cle->val),&(cle->pred->val));
             cle=cle->pred;

        }
      afficher_liste(L);
    }

}

Liste* partition_Liste(Liste* L, Liste* debut, Liste* fin)
{
    int pivot = fin->val;
    Liste* gauche = debut->pred;

    for (Liste *j=debut; j!=fin; j=j->svt) {
        if (j->val < pivot)
        {
            if(!gauche) gauche=debut; else gauche=gauche->svt;
            echange(&(j->val), &(gauche->val));
        }
    }
    if(!gauche) gauche=debut;
    else gauche=gauche->svt;
    echange(&(gauche->val), &(fin->val));

    return gauche;
}
 void Tri_rapide_Liste(Liste* L, Liste* debut, Liste* fin)
 {
    if (debut && fin && debut != fin && debut->pred != fin)
    {
        Liste* p = partition_Liste(L, debut, fin);
        afficher_liste(L);
        Tri_rapide_Liste(L, debut, p->pred);
        Tri_rapide_Liste(L, p->svt, fin);
    }
 }

