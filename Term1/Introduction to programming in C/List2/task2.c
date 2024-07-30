#include <stdio.h>
#include <string.h>

char tekst[1000000+72]={'\0'};

int czyspacja(char a)
{
    if(a==' ' || a=='\t' || a=='\n')
    {
        return 1;
    }
    return 0;
}

void wypisz(int start, int koniec)
{
    int licznik=0;
    for(int i=start; i<koniec; i++)
    {
        if(tekst[i]==' ')
        {
            licznik++;
        }
    }
    if(licznik==0)
    {
        while(start<koniec)
        {
            putchar(tekst[start]);
            start++;
        }
        putchar('\n');
        return;
    }
    int dlugosc=koniec-start-licznik;
    int ilespacji=72-dlugosc;
    int dodac=ilespacji/licznik;
    int reszta=ilespacji%licznik;
    int licz=0;
    for(int i=start; i<koniec; i++)
    {
        if(tekst[i]==' ')
        {
            if(licz<reszta)
            {
                for(int j=0; j<dodac+1; j++)
                {
                    putchar(' ');
                }
                licz++;
            }
            else
            {
                for(int j=0; j<dodac; j++)
                {
                    putchar(' ');
                }
            }
        }
        else
        {
            putchar(tekst[i]);
        }
    }
    putchar('\n');
}

void wczytaj()
{
    int czarek; 
    int i=0;
    int spacja=0;
    while((czarek=getchar())!=EOF)
    {
        if(spacja==1 && czyspacja(czarek))
        {
            continue;
        }
        else if(czyspacja(czarek))
        {
            tekst[i]=' ';
        }
        else
        {
            tekst[i]=czarek;
        }
        if(czyspacja(czarek)!=1)
        {
            spacja=0;
        }
        else
        {
            spacja=1;
        }        
        i++;
    }
}

int linia(int start)
{
    int i=start;
    int j=start+72;
    if(tekst[start+72]==' ')
    {
        while(i<j)
        {
            putchar(tekst[i]);
            i++;
        }
        putchar('\n');
    }
    else
    {
        while(tekst[j]!=' ' && j>i)
        {
            j--;
        }
        if(i==j)
        {
            j=start+72;
            while(tekst[j]!=' ' && tekst[j]!='\0')
            {
                j++;
            }
        }
        wypisz(start,j);
    }
    return j+1;
}

int main()
{
    wczytaj();
    int i=0;
    while(tekst[i]!='\0')
    {
        i=linia(i);
    }
    putchar('\n');
    return 0;
}