#include <stdio.h>

// --- FUNKCJA LICZĄCA ŚREDNIĄ ---
double calculateAvg(int grades[], int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += grades[i];
    }
    return (double)sum / count;
}

// --- FUNKCJA KLASYFIKUJĄCA ŚREDNIĄ ---
void classify(double avg) {
    if (avg < 2.0)
        printf("Srednia: slaba\n");
    else if (avg < 3.5)
        printf("Srednia: przecietna\n");
    else if (avg < 4.5)
        printf("Srednia: dobra\n");
    else
        printf("Srednia: bardzo dobra\n");
}

int main() {
    int grades[20];
    int count;
    char again;

    do {
        // --- LICZBA OCEN ---
        printf("Podaj liczbe ocen (1-20): ");
        scanf("%d", &count);

        while (count < 1 || count > 20) {
            printf("Blad! Liczba ocen musi byc 1-20: ");
            scanf("%d", &count);
        }

        // --- WCZYTYWANIE OCEN ---
        for (int i = 0; i < count; i++) {
            printf("Podaj ocene %d (1-6): ", i + 1);
            scanf("%d", &grades[i]);

            while (grades[i] < 1 || grades[i] > 6) {
                printf("Blad! Ocena musi byc 1-6: ");
                scanf("%d", &grades[i]);
            }
        }

        // --- LICZENIE ŚREDNIEJ ---
        double avg = calculateAvg(grades, count);
        printf("Srednia ocen = %.2f\n", avg);

        // --- ZLICZANIE 1-2 i 5-6 ---
        int failCount = 0;
        int veryGoodCount = 0;

        for (int i = 0; i < count; i++) {
            if (grades[i] <= 2) failCount++;
            if (grades[i] >= 5) veryGoodCount++;
        }

        printf("Liczba ocen dopuszczajacych (1-2): %d\n", failCount);
        printf("Liczba ocen bardzo dobrych (5-6): %d\n", veryGoodCount);

        // --- KLASYFIKACJA ŚREDNIEJ ---
        classify(avg);

        // --- PONOWNE URUCHOMIENIE ---
        printf("Czy chcesz wpisac dane ponownie? (t/n): ");
        scanf(" %c", &again);

    } while (again == 't' || again == 'T');

    return 0;
}
