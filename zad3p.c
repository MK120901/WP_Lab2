#include <stdio.h>

// --- FUNKCJA LICZĄCA STOSUNEK ---
double obliczStosunek(int bez, int z) {
    if (z == 0) return 999999; // zabezpieczenie przed dzieleniem przez 0
    return (double)bez / z;
}

// --- FUNKCJA KLASYFIKUJĄCA ---
void klasyfikuj(double stosunek) {
    if (stosunek < 0.2)
        printf("Kategoria: bardzo aktywny\n");
    else if (stosunek < 0.5)
        printf("Kategoria: aktywny\n");
    else if (stosunek < 1)
        printf("Kategoria: malo aktywny\n");
    else
        printf("Kategoria: prawie brak aktywnosci\n");
}

int main() {
    int wybor;
    char ponownie;

    do {
        printf("MENU:\n1 - rozpocznij analize\n2 - zakoncz program\n");
        scanf("%d", &wybor);

        switch (wybor) {
            case 1: {
                int dni;
                printf("Podaj liczbe dni (1-30): ");
                scanf("%d", &dni);

                while (dni < 1 || dni > 30) {
                    printf("Blad! Podaj od 1 do 30: ");
                    scanf("%d", &dni);
                }

                int aktywnosc[30];
                int bez = 0, z = 0;

                for (int i = 0; i < dni; i++) {
                    printf("Podaj aktywnosc dnia %d (0-300 min): ", i+1);
                    scanf("%d", &aktywnosc[i]);

                    while (aktywnosc[i] < 0 || aktywnosc[i] > 300) {
                        printf("Blad! Podaj 0-300 min: ");
                        scanf("%d", &aktywnosc[i]);
                    }

                    if (aktywnosc[i] == 0) bez++;
                    else z++;
                }

                printf("Dni bez aktywnosci: %d\n", bez);
                printf("Dni z aktywnoscia: %d\n", z);

                double stosunek = obliczStosunek(bez, z);
                printf("Stosunek = %.2f\n", stosunek);

                klasyfikuj(stosunek);

                break;
            }

            case 2:
                printf("Koniec programu.\n");
                return 0;

            default:
                printf("Niepoprawny wybor!\n");
        }

        printf("Czy chcesz wykonac ponownie? (t/n): ");
        scanf(" %c", &ponownie);

    } while (ponownie == 't' || ponownie == 'T');

    return 0;
}
