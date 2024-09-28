#include <stdio.h>
#include <stdlib.h>
#define Max 100

int Min2entiers(int a,int b)
{
    if(a>b)
        return b;
//else
        return a;
}

int Min3entiers(int a,int b,int c)
{
    return Min2entiers(a,Mine2entiers(b,c));
}

long unsigned Sum(int N)
{
    long unsigned s=(N*(N+1))/2;
    return s;
}

long unsigned SumWithout0(int N)
{
    long unsigned s=Sum(N);
    for(int i=10;i<=N;i+=10)
        s-=i;
    return s;
}

//----EXERCICE3----
int lire()
{
    int N;
    do
    {
        printf("\nEntrez le nombre d'element: ");
        scanf("%d",&N);
    }while(N>100 || N<0);
 return N
}

void SaisieElm(int T[Max],int N)
{
    for(int i=0;i<N;i++)
        do
    {
         printf("\nEntrez l'element T[%d]=  ",i);
        scanf("%d",&T[i]);

    }while((T[i]>999)||(T[i]<(-999)));
}

void afficher(int T[Max],int N)
{
    for(int i=0;i<N;i++)
        ptintf("\nTableau[%2d]= %+6d",i,T[i]);
}

int Min_rang(int T[Max],int N,int*rang)
{
   int i_min=0;
  for(int i=1;i<N;i++)
  {
      if(T[i]<T[i_min])
      {
         i_min=i;
         *rang=i_min+1;
      }
  }
  return(int)T[i_min];
}

void delete(int T[Max],int *N,int ind)
{
  int i;
  if(ind>=*N) return;
  for(i=ind;i<(*N-1);i++;i++)
    T[i]=T[i+1];
  *N=*N-1;
}

int main()
{
    printf("%ld",Sum(10));
    printf("\n%ld",SumWithout0(10));
    return 0;
}
