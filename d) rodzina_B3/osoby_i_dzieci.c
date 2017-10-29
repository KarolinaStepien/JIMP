//program wczytujacy i wypisujacy dane o rodzicach i ich dzieciach
#include <stdio.h>
#include <stdlib.h>

struct osoba
{
    char *nazwisko;
    int rok_urodzenia;
    int liczba_dzieci;
    struct osoba *wskaznik;
};

struct osoba * funkcja_nowe_dziecko(struct osoba *rodzic)
{
    struct osoba *dziecko;
    //Karo malloc
    dziecko = (struct osoba *)malloc(sizeof(struct osoba));
    dziecko->wskaznik = rodzic->wskaznik;
    rodzic->wskaznik = dziecko;
    return dziecko;
}

void urodziny_dzieci(struct osoba *rodzic)
{
    int i;
    struct osoba *nowe;
    rodzic->wskaznik = NULL;
    for(i=0;i<rodzic->liczba_dzieci;++i)
    {
        nowe = funkcja_nowe_dziecko(rodzic);
        printf("Wpisz rok urodzenia %d-go dziecka: ", i+1);
        scanf("%d", &nowe->rok_urodzenia);
        nowe->nazwisko = rodzic->nazwisko;
        nowe->liczba_dzieci = 0;
    }
}

void printfowanie(struct osoba *ziomek)
{
    printf("\nOsoba o nazwisku %s\n", ziomek->nazwisko);
    printf("Urodzila sie w roku %d\n", ziomek->rok_urodzenia);
    if(ziomek->liczba_dzieci!=0)
    {
        printf("Ma %d dzieci:\n", ziomek->liczba_dzieci);
    }
    if(ziomek->wskaznik!=NULL)
    {
        printfowanie(ziomek->wskaznik);
    }
}

void min_max(struct osoba rodzic[], struct osoba *min, struct osoba *max)
{
    int n;
    *max = rodzic[0];
    for(n=0;n<3;++n)
    {
        if(rodzic[n].liczba_dzieci==0)
        {
            *min = rodzic[n];
        }
        if(rodzic[n].liczba_dzieci>max->liczba_dzieci)
        {
            *max = rodzic[n];
        }
    }
}

int main(void)
{
    int k;
    struct osoba min;
    struct osoba max;
    struct osoba rodzic[3];

    rodzic[0].nazwisko = "Niebieski";
    rodzic[0].rok_urodzenia = 1964;
    rodzic[0].liczba_dzieci = 3;
    rodzic[1].nazwisko = "Rozowy";
    rodzic[1].rok_urodzenia = 1958;
    rodzic[1].liczba_dzieci = 0;
    rodzic[2].nazwisko = "Fioletowy";
    rodzic[2].rok_urodzenia = 1971;
    rodzic[2].liczba_dzieci = 1;

    for(k=0;k<3;++k)
    {
        printf("Wpisz dane o dzieciach osoby o nazwisku %s\n", rodzic[k].nazwisko);
        urodziny_dzieci(&rodzic[k]);
    }
    for(k=0;k<3;++k)
    {
        printfowanie(&rodzic[k]);
        printf("----------------------\n");
    }
    min_max(rodzic, &min, &max);
    printf("\nOsoba bezdzietna to %s\n", min.nazwisko);
    printf("Osoba z najwieksza iloscia dzieci to %s\n", max.nazwisko);

    return 0;
}
