#include <stdio.h>
#include <math.h>

float dystans(float x,float y,float p,float q)
{
    int zwrot;
    zwrot=sqrt((p-x)*(p-x)+(q-y)*(q-y));
    return zwrot;
}

int main(void)
{
    float wynik,x,y,p,q,m,z;
    int n;
    scanf("%d", &n);
    scanf("%f %f", &m, &z);
    p=m;
    q=z;
    for(int i=1;i<n;i++){
        scanf("%f %f", &x, &y);
        wynik=wynik+dystans(x,y,p,q);
        p=x;
        q=y;
    }
    wynik=wynik+dystans(x,y,m,z);
    printf("%f \n", wynik);
    return 0;
}