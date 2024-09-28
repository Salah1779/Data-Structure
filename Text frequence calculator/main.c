#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 25
#define BL ' '
#define RC '\n'

char epurerblanc()
{
    char c;
    while((c=getchar())==BL);
    return ((char)c);
}
void trouvermot()
{
    char mot[Max],motlu[Max],car;
    int ind, freq=0;
    printf("\nEntrer le mot a rechercher: ");
    scanf("%s",mot);getchar();
    printf("\nEntrer la phrase a traiter: ");
    do
    {
        ind=0;
        car=epurerblanc();
        //if(car==RC) break;
        motlu[ind]=car;
        while(((car=getchar())!=BL)&&
              (car!=RC)
              )
            motlu[++ind]=car;
        motlu[++ind]='\0';
        if(!strcmp(mot,motlu))
            printf("\nLemot apparait dans la phrase %d frequence",++freq);
    }while(car!=RC);
    if(freq==0)
        printf("\nLe mot n'existe pas");

}


char Maj_min(char c)
{
    if(((c>='a')&&(c<='z')))
        return (char)c-32;
    if(((c>='A')&&(c<='Z')))
        return (char)c+32;
}
char Min_maj(char c)
{
    if(((c>='a')&&(c<='z')))
        return (char)c-32;
}
int TransformNum(char c)
{   if((c>='0')&&(c<='9'))
       return (int)'9'-c;
}
int typecar(char c)
{
    if((c>='A')&&(c<='z'))
        return 1;
    if((c>='0')&&(c<='9'))
        return 2;
    if(c==BL)
        return 3;
    if(c=='\t')
        return 4;
    return 5;
}
void Transformer_phrase()
{
    int h;
    char c;
    while((c=getchar())!=RC)
    {
        h=typecar(c);
        switch(h)
        {
           case 1:
               printf("%c",Maj_min(c));break;
           case 2:
               printf("%d",TransformNum(c));break;
           case 3:
               printf("BL");break;
           case 4:
               printf("TAB");break;
           default: break;
        }
    }
 }

 void frequence_car(char c)
 {
    char carlu;
    int freq=0;
    while((carlu=getchar())!=RC)
        if(carlu==c)
          freq++;
    printf("\nla frequence de %c est freq=%d",c,freq);
 }
 int frequencetouscar(int freq[37])
{
    int ind;
    int total=0;
    char carlu;
    for(ind=0;ind<37;ind++)
        freq[ind]=0;
    while((carlu=getchar())!=RC)
    {
        total++;
        ind=typecar(carlu);
        switch(ind)
        {
            case 1:
                carlu=Min_maj(carlu);freq[carlu-'A']++;break;
            case 2:
                freq[26+(carlu-'0')]++;break;
            default:
                freq[36]++;break;

        }
    }
    return total;
}
void affichage_freq(int freq[])
{
    int n=0;
    for(int i=0;i<37;i++)
    {
     if(freq[i]>0)
     {
       if(i<=26)
             printf("\n  freq[%c]=%d ",'A'+i,freq[i]);
        else if((i>26)&&(i<36))
             printf("\n  freq[%d]=%d ",n++,freq[i]);
        else
        printf("\n  freq[autre]=%d",freq[i]);
     }

    }
}
int main()
{
    //trouvermot();
    int frequence[37];
   //printf("\n on calcule la frequence de 'a':");

   //frequence_car('a');

     printf("\nla phrase a saisir: ");
      //Transformer_phrase();
     int total=frequencetouscar(frequence);
     printf("\nTa phrase contient :%d caracteres .\n",total);
    printf("\nl'affichage des frequences... \n");

    affichage_freq(frequence);

    return 0;
}
