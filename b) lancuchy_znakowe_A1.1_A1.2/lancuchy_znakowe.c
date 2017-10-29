//program do ktorego podajemy z klawiatury ciagi znakow a on umieszcza je w tablicy dwuwymiarowej
#include <stdio.h>
#include <string.h>

void dane(char tab[][12], int j)
{
    printf("Wprowadz wyraz: ");
    scanf("%s", &tab[j]);
}

int main(void)
{
    int i, j, min, char_int1, char_int2;
    char tmp;
    char tablica[5][12];
    for(i=0;i<5;++i)
    {
        dane(tablica, i);
    }
    //od przodu
    for(i=0;i<5;++i)
    {
        printf("%s ", tablica[i]);
    }
    printf("\n");
    //od tylu
    for(i=4;i>=0;--i)
    {
        printf("%s ", tablica[i]);
    }
}
