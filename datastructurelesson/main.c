#include <stdio.h>
#include <stdlib.h>
#define Absolue(a) (a)<0? (-a):(a)
int main()
{
 //Les connecteurs Logiques---
  printf("Test des instructions\n");
  if(3&&7) printf("3&&7 est vrai\n");
  else  printf("3&&7 est faux\n");

  if((1<2)&&(3<4)) printf("1<2&&3<4 est vrai\n");
  else  printf("1<2&&3<4 est faux\n");

 int a=1,b=0;
  if(a&&(b==0)) printf("a&&(b==0) est vrai\n");
  else  printf("a&&(b==0) est faux\n");

  if(3||7) printf("3||7 est vrai\n");
  else  printf("3||7 est faux\n");

 int x;
   if((x-x)||(7>3)) printf("x-x||7>3 est vrai\n");
  else  printf("x-x||7>3 est faux\n");

 int c=1;
   if(!c) printf("!c est vrai\n");
  else  printf("!c est faux\n");

  c=0;
   if(!c) printf("!c est vrai\n");
   else  printf("!c est faux\n");

  c=1;
  if(!(c>1)) printf("!(c>1) est vrai\n");
  else  printf("!(c>1) est faux\n");
  printf("\n");

//Affectation et incrementation---
  int z=2; printf("z=%d\n",z);
  z++; printf("z=%d\n",z);
  ++z; printf("z=d\n",z);
  z--; printf("z=%d\n",z);
  --z; printf("z=%d\n",z);
  b=z++;printf("z=%d,b=%d\n",z,b);
  b=--z;printf("z=%d,b=%d\n",z,b);
 printf("\n");

  //Conversion de Type---
 float f=50.0;
 f=f*1/10;  printf("f=%.1f\n",f);
 f=50.0;
 f*=1/10;    printf("f=%d\n",f);
 printf("\n");

//operateur equivalent if else---
 printf("La valeur absolue de %d est %d\n",-10,Absolue(-10));
 printf("La valeur absolue de %d est %d\n",10,Absolue(10));
 printf("\n");

//Base de numerotation---
 printf("sans mention de la base:\t%o\t%x\t%X\n",123,123,123);
 printf("sans mention de la base:\t%#o\t%#x\t%#X\n",123,123,123);
 printf("%+d\n",12);
 printf("+%d\n",12);
  printf("\n");

 //Largeur edition---
 printf("%d\n",1234);
 printf("%2d\n",1234);
 printf("%8d\n",1234);
 printf("%08d\n",1234);
  printf("\n");

 //Alignement a droite et a gauche---
 printf(" affichage a droite %8d* par defaut\n affichage a gauche %-8d*",23,23);
 printf("\n");

 //format pour un nombre a virgule flottante---
 printf("%f\n",1.234);
 printf("%e %e %e\n",0.1234,1.234,12.34);
 printf("%g %g %g\n",123.0,123.,123.4);
 printf("%g\n",1.234e2);
 printf("%g %G\n",0.0000123,1234567.0);
  printf("\n");

 //precision---
 printf("=%5.3f\n=%10.6f\n",1.2345,1.2345);
 printf("\n");

 //Nombre maximal de caractere a afficher---
 printf("%6.1s\n%6.2s\n%6.3s\n%6.4s\n%6.5s\n%6.6s\n","chaine","chaine","chaine","chaine","chaine","chaine");
  printf("\n");

 //format pour une adresse---
 int i;
 printf("%p\t%d\t%X\n",&i,&i,&i);

 int val1,val2,val3;

 char car1,car2,car3;
  scanf("%c %c %c\n",&car1,&car2,&car3);
 printf("car1=%c\tcar2=%c\tcar3=%c\n",car1,car2,car3);








    return 0;
}
