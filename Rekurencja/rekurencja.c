#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// zwraca liczbę wystąpień cyfry k w liczbie x  - GOTOWE
int ile(int x, int k)
{
    // przypadek elementarny - x jest jednocyfrowa
    if ((x >= 0) && (x <10))
    {
        return x==k;
    }
    // przypadek rekurencyjny
    else
    {
        return ile(x/10, k) + (x%10 == k);
    }
}


//zwraca liczbę wystąpień cyfry k we wszystkichelementach tablicy - GOTOWE
int zlicz1(int n, int *a, int k)
{
    // przypadek elementarny - tablica pusta
    if (n == 0)
    {
        return 0;
    }
    // przypadek rekurencyjny
    else
    {
        return ile(a[n-1], k) + zlicz1(n-1, a, k);
    }
}

 // zwraca sumę cyfr liczby x  - GOTOWE
int suma_cyfr(int x)
{
    // przypadek elementarny - x jest cyfrą
    if ((x >= 0) && (x <10))
    {
        return x;
    }
    // przypadek rekurencyjny
    else
    {
        return x%10 + suma_cyfr(x/10);
    }
} 

//zwraca maksymalną wartość sumy cyfr spośród wszystkich elementów tablicy - GOTOWE
int zlicz2(int n, int *a)
{
    // przypadek elementarny - tablica pusta
    if (n == 0)
    {
        return 0;
    }
    // przypadek rekurencyjny - wybierz albo ostatni element tablicy albo największą sumę cyfr z n-1 elementów
    else
    {
        return max(suma_cyfr(a[n-1]), zlicz2(n-1, a));
    }
}

//zwraca indeks elementu tablicy o maksymalnej wartości sumy cyfr
int zlicz3(int n, int *a, int max_suma, int max_index, int index) {
    if (index == n) 
    {
        return max_index;
    }
    else 
    {
        int suma = suma_cyfr(a[index]);
            if (suma > max_suma) {
        max_suma = suma;
        max_index = index;
    }
        return zlicz3(n, a, max_suma, max_index, index + 1);
    }
}


int main()
{

    // wczytanie rozmiaru tablicy
    int n; 
    printf("Podaj rozmiar tablicy: ");
    scanf("%d", &n);

    // alokacja tablicy
    int *tab = malloc(n * sizeof(int));

    // wypelnij tablice losowymi wartosciami
    for (int i = 0; i < n; i++)
    {
        tab[i] = rand() % 1000;  //(od 0 do 999)
    }

    // Wyswietl tablice
    for (int i = 0; i < n; i++)
    {
        printf("%d ", tab[i]);
    }

    // wczytaj szukaną cyfre k
    int k;
    printf("Podaj cyfre k: ");
    scanf("%d", &k);

    // Wyswietl wyniki
    int wystepienia = zlicz1(n, tab, k);
    printf("Wystepienia cyfry %d: %d\n", k, wystepienia);

    int max_suma = zlicz2(n, tab);
    printf("Maksymalna suma cyfr: %d\n", max_suma);

    int max_index = zlicz3(n, tab, suma_cyfr(tab[0]), 0, 0);
    printf("Indeks elementu o maksymalnej sumie cyfr: %d\n", max_index);

    return 0;

}