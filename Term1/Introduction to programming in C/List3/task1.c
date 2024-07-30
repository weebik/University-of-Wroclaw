#include <stdio.h>
#include <string.h>
#include <math.h>

#define VARCNT 3

char swap(char a)
{
    char b;
    if(a=='F')
    {
        b='T';
        return b; 
    }
    else
    {
        b='F';
        return b;
    }
}

int main()
{
    int szerokosc=VARCNT;
    int dlugosc=1 << VARCNT;
    char tab[dlugosc][szerokosc];
    for(int i=0, blok=dlugosc/2; i<szerokosc; blok /= 2, i++)
    {
        char znak = 'F';
        for(int j=0; j<dlugosc; j++)
        {
            if(j % blok == 0)
            {
                znak=swap(znak);
            }
            tab[j][i]=znak;
            // zaleznie od 'j' i 'blok' zmień znak z 'F' na 'T' lub na odwrot
        }
    }
    for(int i=0; i<dlugosc;i++)
    {
        for(int j=0; j<szerokosc; j++)
        {
            putchar(tab[i][j]);
        }
        putchar('\n');
    }
    return 0;
}