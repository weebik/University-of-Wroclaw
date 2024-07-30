#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

//wiem ze nie jest to najbardziej zoptymalizowane ale dziala

int losujliczby(int n)
{
    long dol = pow(10,n-1);
    long gora = pow(10,n);
    int liczba = rand()%(gora - dol +1)+ dol;
    return liczba;
}

int smenu()
{
    int n;
    printf("Maszyna do interaktywnego cwiczenia dodawania i odejmowania \n Tworca: Krystian Cwiklinski\n Aby wyjsc uzyj komendy 'ctrl + c' \n \n Na ilucyfrowych liczbach chcesz ćwiczyć: ");
    while(scanf("%d", &n)!=1) n=getchar();
    printf("\n Losowanie... \n");
    return n;
}

int losuj(void)
{
    int los=rand();
    if(los%2==0)
    {
        return 1;
    }
    return 0;
}

int main(void)
{
    srand(time(NULL));
    long wynik, odpowiedz;
    int n=smenu();
    while(1==1)
    {
        long a = losujliczby(n);
        long b = losujliczby(n);
        if(losuj())
        {
            wynik=a+b;
            printf("%ld + %ld \n", a, b);
            printf("Podaj wynik: ");
            while(scanf("%ld", &odpowiedz)!=1) odpowiedz=getchar();
            while(odpowiedz!=wynik)
            {
                printf("Zly wynik podaj liczbe jeszcze raz: ");
                while(scanf("%ld", &odpowiedz)!=1) odpowiedz=getchar();
            }
            printf("Wynik poprawny \n \n");
        }
        else
        {   
            if(a<b)
            {
                wynik=b-a;
                printf("%ld - %ld \n", b, a);
                printf("Podaj wynik: ");
                while(scanf("%ld", &odpowiedz)!=1) odpowiedz=getchar();
                while(odpowiedz!=wynik)
                {
                    printf("Zly wynik podaj liczbe jeszcze raz: ");
                    while(scanf("%ld", &odpowiedz)!=1) odpowiedz=getchar();
                }
                printf("Wynik poprawny \n \n");
            }
            else
            {
                wynik=a-b;
                //printf("Wylosowano odejmowanie liczb: %ld - %ld \n", a, b);
                printf("%ld - %ld \n", a, b);
                printf("Podaj wynik: ");
                while(scanf("%ld", &odpowiedz)!=1) odpowiedz=getchar();
                while(odpowiedz!=wynik)
                {
                    printf("Zly wynik podaj liczbe jeszcze raz: ");
                    while(scanf("%ld", &odpowiedz)!=1) odpowiedz=getchar();
                }
                printf("Wynik poprawny \n \n");
            }
        }
    }
    return 0;
}