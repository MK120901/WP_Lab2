#include <stdio.h>

// --- FUNKCJA LICZĄCA ŚREDNIĄ ---
double obliczSrednia(int oceny[], int liczbaOcen) {
    int suma = 0;
    for (int i = 0; i < liczbaOcen; i++) {
        suma += oceny[i];
    }
    return (double)suma / liczbaOcen;
}

// --- FUNKCJA KLASYFIKUJĄCA ŚREDNIĄ ---
void klasyfikujSrednia(double srednia) {
    if (srednia < 2.0)
        printf("Srednia: slaba\n");
    else if (srednia < 3.5)
        printf("Srednia: przecietna\n");
    else if (srednia < 4.5)
        printf("Srednia: dobra\n");
    else
        printf("Srednia: bardzo dobra\n");
}

int main() {
    int oceny[20];
    int liczbaOcen;
    char ponownie;

    do {
        // --- POBIERANIE LICZBY OCEN ---
        printf("Podaj liczbe ocen (1-20): ");
        scanf("%d", &liczbaOcen);

        while (liczbaOcen < 1 || liczbaOcen > 20) {
            printf("Blad! Liczba ocen musi byc od 1 do 20: ");
            scanf("%d", &liczbaOcen);
        }

        // --- WCZYTYWANIE OCEN ---
        for (int i = 0; i < liczbaOcen; i++) {
            printf("Podaj ocene %d (1-6): ", i + 1);
            scanf("%d", &oceny[i]);

            while (oceny[i] < 1 || oceny[i] > 6) {
                printf("Blad! Ocena musi byc od 1 do 6: ");
                scanf("%d", &oceny[i]);
            }
        }

        // --- OBLICZANIE ŚREDNIEJ ---
        double srednia = obliczSrednia(oceny, liczbaOcen);
        printf("Srednia ocen = %.2f\n", srednia);

        // --- ZLICZANIE OCEN 1–2 i 5–6 ---
        int dopuszczajace = 0;
        int bardzoDobre = 0;

        for (int i = 0; i < liczbaOcen; i++) {
            if (oceny[i] <= 2) 
                dopuszczajace++;
            if (oceny[i] >= 5) 
                bardzoDobre++;
        }

        printf("Liczba ocen dopuszczajacych (1-2): %d\n", dopuszczajace);
        printf("Liczba ocen bardzo dobrych (5-6): %d\n", bardzoDobre);

        // --- KLASYFIKACJA ŚREDNIEJ ---
        klasyfikujSrednia(srednia);

        // --- PYTANIE O KOLEJNE DANE ---
        printf("Czy chcesz podac oceny ponownie? (t/n): ");
        scanf(" %c", &ponownie);

    } while (ponownie == 't' || ponownie == 'T');

    return 0;
}
