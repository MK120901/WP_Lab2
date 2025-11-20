#include <stdio.h>
#include <stdbool.h>

// --- FUNKCJE ---
void checkBalance(double balance) {
    printf("Twoje saldo: %.2f\n", balance);
}

double deposit(double balance, double amount) {
    if (amount <= 0) {
        printf("Nie mozna wplacic ujemnej lub zerowej kwoty!\n");
        return balance;
    }
    return balance + amount;
}

double withdraw(double balance, double amount) {
    if (amount <= 0) {
        printf("Nie mozna wyplacic ujemnej lub zerowej kwoty!\n");
        return balance;
    }
    if (amount > balance) {
        printf("Brak wystarczajacych srodkow!\n");
        return balance;
    }
    return balance - amount;
}

// --- PROGRAM GLOWNY ---
int main() {
    const int PIN = 1234;
    int userPin;
    int attempts = 0;
    double balance = 1000.0; // przykładowe saldo
    int choice;
    double amount;

    // ======= WERYFIKACJA PIN =======
    while (attempts < 3) {
        printf("Wpisz PIN: ");
        scanf("%d", &userPin);

        if (userPin == PIN) {
            break;
        } else {
            attempts++;
            printf("Zly PIN! Pozostale proby: %d\n", 3 - attempts);
        }
    }

    if (attempts == 3) {
        printf("3 bledne proby. Zablokowano.\n");
        return 0;
    }

    // ======= MENU =======
    while (true) {
        printf("\n=== MENU ===\n");
        printf("1. Sprawdz saldo\n");
        printf("2. Wplac srodki\n");
        printf("3. Wyplac srodki\n");
        printf("4. Wyjdz\n");
        printf("Wybierz opcje: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            checkBalance(balance);
            break;

        case 2:
            printf("Kwota do wplaty: ");
            scanf("%lf", &amount);
            balance = deposit(balance, amount);
            break;

        case 3:
            printf("Kwota do wyplaty: ");
            scanf("%lf", &amount);
            balance = withdraw(balance, amount);
            break;

        case 4:
            printf("Do widzenia!\n");
            return 0;

        default:
            printf("Nie ma takiej opcji. Sprobuj ponownie.\n");
        }
    }

    return 0;
}
