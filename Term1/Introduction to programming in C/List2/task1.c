#include <stdio.h>
#include <string.h>

int czypomiedzy(int a)
{
    if(a>=32 && a<127)
    {
        return 1;
    }
    return 0;
}

int czypomijam(char a, char *b)
{
    int i=0;
    while(b[i]!='\0')
    {
        if(a==b[i])
        {
            return 1;
        }
        i++;
    }
    return 0;
}

int czyznak(int a)
{
    if(a=='?' || a=='!' || a=='.')
    {
        return 1;
    }
    return 0;
}

int duza(char a)
{
    if(a >= 'a' && a<='z')
    {
        a=a-'a'+'A';
    }
    return a;
}

int mala(char a)
{
    if(a >= 'A' && a<='Z')
    {
        a=a-'A'+'a';
    }
    return a;
}

int main(int argc, char *argv[])
{
    if(argc > 2)
    {
        printf("BLAD\n");
        return 0;
    }
    if(argc==2)
    {
        int i=0;
        while(argv[1][i]!='\0')
        {
            if(czypomiedzy(argv[1][i])!=1)
            {
                printf("BLAD");
                return 0;
            }
            i++;
        }
    }
    int czyduza = 1;
    int czyspacja = 1;
    int nowalinia = 0;
    int tekst;
    while((tekst=getchar()) != EOF)
    {
        if(nowalinia==1 && czyznak(tekst)!=1)
        {
            putchar('\n');
            czyduza=1;
            czyspacja=1;
            nowalinia=0;
        }
        if(czyspacja==1 && tekst==' ')
        {
            continue;
        }
        if(argc==2 && czypomijam(tekst,argv[1])==1)
        {
            continue;
        }
        if(czypomiedzy(tekst)!=1)
        {
            continue;
        }
        if(tekst==' ')
        {
            czyspacja=1;
        }
        else
        {
            czyspacja=0;
        }
        if(czyduza==1)
        {
            tekst=duza(tekst);
            czyduza=0;
        }
        else
        {
            tekst=mala(tekst);
        }
        putchar(tekst);
        if(czyznak(tekst))
        {
            nowalinia=1;
        }
        if(tekst==' ')
        {
            czyduza=1;
        }
    }
    return 0;
}