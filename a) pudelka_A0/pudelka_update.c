//program sprawdzajacy czy ktore pudelka mieszcza sie w ktorych
#include <stdio.h>
#include <string.h>

struct struktura
{
    char identyfikator[1];
    double a, b, c;
};

void dane(struct struktura tab[])
{
    int i;
    for(i=0;i<3;++i)
    {
        printf("\nPodaj jednoliterowy identyfikator: ");
        scanf("%s", &tab[i].identyfikator);
        printf("Podaj pierwszy wymiar pudelka: ");
        scanf("%lf", &tab[i].a);
        printf("Podaj drugi wymiar pudelka: ");
        scanf("%lf", &tab[i].b);
        printf("Podaj trzeci wymiar pudelka: ");
        scanf("%lf", &tab[i].c);
    }
}

void porownanie(struct struktura tab[], char wyn[3][3])
{
    double roznica_szerokosci, roznica_dlugosci, roznica_wysokosci;
    int i, j;
    for(i=0;i<3;++i)
    {
        for(j=i+1;j<3;++j)
        {
            roznica_szerokosci = tab[i].a - tab[j].a;
            roznica_dlugosci = tab[i].b - tab[j].b;
            roznica_wysokosci = tab[i].c - tab[j].c;
            if (roznica_szerokosci > 0 && roznica_dlugosci > 0 && roznica_wysokosci > 0) {
                wyn[i][j]='>';
            }
            else if (roznica_szerokosci < 0 && roznica_dlugosci < 0 && roznica_wysokosci < 0) {
                wyn[i][j]='<';
            }
            else if (roznica_szerokosci == 0 && roznica_dlugosci == 0 && roznica_wysokosci == 0) {
                wyn[i][j]='=';
            }
            else {
                wyn[i][j]='-';
            }

        }
    }
}

int main(void)
{
    int i, j;
    struct struktura tablica[3];
    char wyniki[3][3];
    dane(tablica);
    porownanie(tablica, wyniki);
    for(i=0;i<3;++i)
    {
        for(j=i+1;j<3;++j)
        {
            printf("'<' oraz '>' oznaczaja ktore pudelko jest mniejsze\
                   i miesci sie w sasiednim, a ktore wieksze i zawiera poprzednie\
                   '-' oznacza, ze zadne z pudelek nie miesci sie w drugim\
                   '=' pudelka maja rowne wymiary");
            printf("%s", tablica[i].identyfikator);
            printf("%c", wyniki[i][j]);
            printf("%s\n", tablica[j].identyfikator);
        }
    }
}
