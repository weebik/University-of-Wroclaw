#include <stdio.h>
#include <string.h>

int tablica[100 + 7][100 + 7];
int cienie[100 + 7][100 + 7];

void wypelnij(int szerokosc, int wysokosc)
{
    for (int i = 0; i < wysokosc; i++)
    {
        for (int j = 0; j < szerokosc; j++)
        {
            cienie[i][j] = 0;
        }
    }
}

void wczytaj(int szerokosc, int wysokosc)
{
    char c;
    for (int i = 0; i < wysokosc; i++)
    {
        for (int j = 0; j < szerokosc; j++)
        {
            c = getchar();
            if (c == '.')
            {
                tablica[i][j] = 0;
            }
            else
            {
                tablica[i][j] = c - '0';
            }
        }
        getchar();
    }
}

int zlicz(int szerokosc, int wysokosc)
{
    int licznik = 0;
    for (int i = 0; i < wysokosc; i++)
    {
        for (int j = 0; j < szerokosc; j++)
        {
            if (cienie[i][j] == 1)
            {
                continue;
            }
            if (tablica[i][j] == 0)
            {
                continue;
            }
            if (tablica[i][j] == 9)
            {
                licznik++;
                continue;
            }
            else
            {
                tablica[i][j] = tablica[i][j] + 1;
            }
        }
    }
    return licznik;
}

int main()
{
    long long dni, licznikdni = 0;
    long long szyszunie = 0;
    int szerokosc, wysokosc;
    scanf("%d %d %lld", &szerokosc, &wysokosc, &dni);
    getchar();
    wczytaj(szerokosc, wysokosc);
    while (licznikdni < dni)
    {
        wypelnij(szerokosc, wysokosc);
        for (int i = 0; i < wysokosc; i++)
        {
            for (int j = szerokosc - 1; j >= 0; j--)
            {
                for (int n = 1; n <= tablica[i][j] && j - n >= 0; n++)
                {
                    cienie[i][j - n] = 1;
                }
            }
        }
        szyszunie += zlicz(szerokosc, wysokosc);
        wypelnij(szerokosc, wysokosc);
        for (int i = wysokosc - 1; i >= 0; i--)
        {
            for (int j = 0; j < szerokosc; j++)
            {
                for (int n = 1; n <= tablica[i][j] && i - n >= 0; n++)
                {
                    cienie[i - n][j] = 1;
                }
            }
        }
        szyszunie += zlicz(szerokosc, wysokosc);
        wypelnij(szerokosc, wysokosc);
        for (int i = 0; i < wysokosc; i++)
        {
            for (int j = 0; j < szerokosc; j++)
            {
                for (int n = 1; n <= tablica[i][j] && n + j < szerokosc; n++)
                {
                    cienie[i][j + n] = 1;
                }
            }
        }
        szyszunie += zlicz(szerokosc, wysokosc);
        licznikdni++;
    }
    printf("%lld\n", szyszunie);
    return 0;
}