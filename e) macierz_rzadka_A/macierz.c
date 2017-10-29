//program wybierajacy niezerowe elementy z gestej macierzy i umieszczajacy je w tablicy rzadka
#include <stdio.h>
#define MAX 4

struct niezerowy_element
{
    int x, y;
    double wartosc;
};

void funkcja(struct niezerowy_element rzadka[MAX], int i, int j, double macierz[3][3], int *licznik)
{
    if(macierz[i][j]!=0) {
        rzadka[*licznik].x=i;
        rzadka[*licznik].y=j;
        rzadka[*licznik].wartosc=macierz[i][j];
        (*licznik)++;
    }
}

int main(void)
{
    double macierz[3][3] = {
    {0, 6.4, 0},
    {8.69, 0, 13},
    {0, 27.1, 0}
    };

    struct niezerowy_element rzadka[MAX];
    int i, j, licznik=0;
    for(i=0;i<3;++i)
    {
        for(j=0;j<3;++j)
        {
            funkcja(rzadka, i, j, macierz, &licznik);
        }
    }
    for(i=0;i<MAX;++i)
    {
        printf("(%d, %d) --> %3.2f\n", rzadka[i].x, rzadka[i].y, rzadka[i].wartosc);
    }
    return 0;
}
