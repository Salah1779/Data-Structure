#include <stdio.h>
#include <stdlib.h>

unsigned int Nbjour_par_mois(unsigned int m,unsigned int a)
{
    if((m>=1) && (m<=7))
    {
        if(m%2==1)
            return 31;
        if(m==2)
        {
            if(a%4==0)
                return 29;
            return 28;
        }
        return 30;
    }
    if((m>=8) && (m<=12))
    {
        if(m%2==0)
            return 31;
        return 30;
    }
}
int Date_valide(unsigned int j,unsigned int m,unsigned int a)
{
    if((a>=1901) && (a<=2099))
    {
        if((m>=1) && (m<=12))
        {
            if((j>=1) && (j<=Nbjour_par_mois(m,a)))
                return 1;
        }
    }
    return 0;
}
unsigned int Nbjour_mois(unsigned int m,unsigned int a)
{
    int s=0;
    for(int i=1;i<m;i++)
       s+=Nbjour_par_mois(i,a);
    return s;
}
unsigned int Nbjour_annee(unsigned int a)
{
    unsigned int A=(a-1901);
    return A*36+A/4;
}
unsigned int Nbjour_dans_mois(unsigned int j)
{
    return j-1;
}
unsigned long int Nbjour_diff(unsigned int j,unsigned int m,unsigned int a)
{
    unsigned long int Total=Nbjour_annee(a)+Nbjour_dans_mois(j)+Nbjour_mois(m,a);
    return Total;
}
void afficherLejour(unsigned int i,unsigned int j,unsigned int m,unsigned int a)
{
    switch(i)
    {
        case 0:printf("Le jour de la date %d/%d/%d est :Mardi",j,m,a);break;
        case 1:printf("Le jour de la date %d/%d/%d est :Mercredi",j,m,a);break;
        case 2:printf("Le jour de la date %d/%d/%d est :Jeudi",j,m,a);break;
        case 3:printf("Le jour de la date %d/%d/%d est :Vendredi",j,m,a);break;
        case 4:printf("Le jour de la date %d/%d/%d est :Samedi",j,m,a);break;
        case 5:printf("Le jour de la date %d/%d/%d est :Dimanche",j,m,a);break;
        case 6:printf("Le jour de la date %d/%d/%d est :Lundi",j,m,a);break;
    }
}
void Date(unsigned int j,unsigned int m,unsigned int a)
{
    if(Date_valide(j,m,a))
    {
        unsigned int i=Nbjour_diff(j,m,a)%7;
        afficherLejour(i,j,m,a);
    }
    else
    printf("La date n'est pas valide");
}
int main()
{
     unsigned int day, month, year;


    printf("Entrez le jour (1-31) : ");
    scanf("%u", &day);
    printf("Entrez le mois (1-12) : ");
    scanf("%u", &month);
    printf("Entrez l'année (1901-2099) : ");
    scanf("%u", &year);


    Date(day, month, year);

}
