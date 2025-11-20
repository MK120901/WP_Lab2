#include <stdio.h>

// --- FUNKCJE KONWERSJI DŁUGOŚCI ---
double cm_na_m(double x) { return x / 100.0; }
double m_na_km(double x) { return x / 1000.0; }

// --- FUNKCJA KONWERSJI MASY ---
double g_na_kg(double x) { return x / 1000.0; }

// --- FUNKCJE KONWERSJI TEMPERATURY ---
double c_na_f(double x) { return x * 1.8 + 32; }
double f_na_c(double x) { return (x - 32) / 1.8; }

int main() {
    int wybor, podwybor;
    double wartosc, wynik;
    char dalej;

    do {
        printf("\n--- KONWERTER JEDNOSTEK ---\n");
        printf("1 - Dlugosc\n");
        printf("2 - Masa\n");
        printf("3 - Temperatura\n");
        printf("Wybierz kategorie: ");
        scanf("%d", &wybor);

        switch (wybor) {
            case 1: // DŁUGOŚĆ
                printf("1 - cm -> m\n");
                printf("2 - m -> km\n");
                printf("Wybierz kierunek: ");
                scanf("%d", &podwybor);

                printf("Podaj wartosc: ");
                scanf("%lf", &wartosc);

                if (wartosc < 0) {
                    printf("Blad: wartosc nie moze byc ujemna.\n");
                    break;
                }

                if (podwybor == 1) wynik = cm_na_m(wartosc);
                else wynik = m_na_km(wartosc);

                printf("Wynik: %.2f\n", wynik);
                break;

            case 2: // MASA
                printf("Konwersja g -> kg\n");
                printf("Podaj wartosc (nieujemna): ");
                scanf("%lf", &wartosc);

                if (wartosc < 0) {
                    printf("Blad: masa nie moze byc ujemna.\n");
                    break;
                }

                wynik = g_na_kg(wartosc);
                printf("Wynik: %.2f kg\n", wynik);
                break;

            case 3: // TEMPERATURA
                printf("1 - C -> F\n");
                printf("2 - F -> C\n");
                printf("Wybierz kierunek: ");
                scanf("%d", &podwybor);

                printf("Podaj wartosc: ");
                scanf("%lf", &wartosc);

                if (podwybor == 1) wynik = c_na_f(wartosc);
                else wynik = f_na_c(wartosc);

                printf("Wynik: %.2f\n", wynik);
                break;

            default:
                printf("Niepoprawny wybor!\n");
        }

        printf("Czy chcesz konwertowac dalej? (t/n): ");
        scanf(" %c", &dalej);

    } while (dalej == 't' || dalej == 'T');

    return 0;
}
