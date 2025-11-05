#include <stdio.h>
#include <stdbool.h>
// biblioteka aby użyć funkcji potęgowania - pow() (opcjonalnie)
#include <math.h> 

double calculateBMI(double weight, double height) {
    // oblicz BMI i zwróć wartość
}

int main() {
    double weight, height;
    char choice;

    do {
        // użytkownik wprowadza wagę i wzrost
        printf("Podaj wage (kg): ");
        scanf("%lf", &weight);
        
        printf("Podaj wzrost (cm): ");
        scanf("%lf", &height);
        
        // obliczanie BMI
        double bmi = calculateBMI(weight, height);
        printf("BMI = %.2f\n", bmi);
        
    } while (true);

    return 0;
}