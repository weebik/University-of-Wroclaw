#include <stdio.h>
#include <string.h>

#define MAXLEN 10000

int mala(char a)
{
    if(a<91 && a>64)
    {
        return a+32;
    }
    else
    {
        return a;
    }
}

int nastepne(char wzorzec[], char tekst[], int poczatkowa)
{
    int dlugosc=strlen(wzorzec);
    for(int i=poczatkowa; tekst[i]!='\0'; i++)
    {
        int licznik=0;
        for(int j=0; j<dlugosc; j++)
        {
            if(mala(wzorzec[j])!=mala(tekst[i+licznik]))
            {
                break;
            }
            if(j==dlugosc-1)
            {
                return i;
            }
            licznik++;
        }
    }
    return -1;
}

void raportuj(char wzorzec[], char tekst[], int nr_linii)
{
    int dlugosc=strlen(tekst);
    int x=0;
    if(nastepne(wzorzec,tekst,x)>-1)
    {
        printf("%d: ", nr_linii);
        for(int i=0; i<=dlugosc; i++)
        {
            int z=nastepne(wzorzec,tekst,x);
            if(z>-1)
            {
                printf("%d " ,z);
                x=z+1;
            }
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[])
{
    char wzorzec[MAXLEN];
    char tekst[MAXLEN];
    if(argc!=2)
    {
        printf("BLAD\na.out [WZORZEC]\n");
        return 0;
    }
    int j=0;

    while(argv[1][j]!='\0')
    {
        wzorzec[j]=argv[1][j];
        j++;
    }
    for(int i=1; fgets(tekst, MAXLEN, stdin)!=NULL; i++)
    {
        raportuj(wzorzec, tekst, i);
    }
    return 0;
}