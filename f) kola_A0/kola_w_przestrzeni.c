//program ktory sprawdza czy kola maja czesci wspolne
#include <stdio.h>
#include <string.h>
#include <math.h>

struct struktura
{
    char id[1];
    int a, b;
    double r;
};

void dane(struct struktura tab[], int j)
{
    printf("\nPodaj id kola: ");
    scanf("%s", &tab[j].id);
    printf("Podaj x srodka kola: ");
    scanf("%d", &tab[j].a);
    printf("Podaj y srodka kola: ");
    scanf("%d", &tab[j].b);
    printf("Podaj promien kola: ");
    scanf("%lf", &tab[j].r);
}

void spr(struct struktura tab[], char wyn[][3])
{
    int i, j;
    double odl_miedzy_srodkami, suma_promieni;
    for(i=0;i<3;++i)
    {
        for(j=i+1;j<3;++j)
        {
            odl_miedzy_srodkami=sqrt(pow(tab[i].a-tab[j].a, 2)+pow(tab[i].b-tab[j].b, 2));
            suma_promieni=tab[i].r+tab[j].r;
            if(odl_miedzy_srodkami>suma_promieni) {
                wyn[i][j]='-';
            } else {
                wyn[i][j]='+';
            }
        }
    }
}

int main(void)
{
    int i, k;
    char wyniki[3][3];
    struct struktura tablica[3];
    for(i=0;i<3;++i)
    {
        dane(tablica, i);
    }
    spr(tablica, wyniki);
    printf("'+' oznacza ze kola maja czesc wspolna, '-' ze jej nie maja\n");
    for(i=0;i<3;++i)
    {
        for(k=i+1;k<3;++k)
        {
            printf("%s %c %s\n", tablica[i].id, wyniki[i][k], tablica[k].id);
        }
    }

    return 0;
}
