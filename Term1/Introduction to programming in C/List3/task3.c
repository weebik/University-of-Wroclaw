#include <stdio.h>

int tab[1000000 + 7];
int odwiedzone[1000000 + 7];

void wczytaj(int n)
{
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tab[i]);
    }
}

int cykl(int i)
{
    long long licznik = 1;
    int start = tab[i];
    int pierwsza = start;
    int druga = tab[pierwsza];
    while (druga != start)
    {
        pierwsza = druga;
        druga = tab[pierwsza];
        odwiedzone[druga] = 1;
        licznik++;
    }
    return licznik;
}

int main()
{
    int n;
    long long maxcykl = 0;
    scanf("%d\n", &n);
    wczytaj(n);
    for (int i = 1; i <= n; i++)
    {
        if (odwiedzone[i] == 1)
        {
            continue;
        }
        if (maxcykl < cykl(i))
            maxcykl = cykl(i);
    }
    printf("%lld\n", maxcykl);
    return 0;
}