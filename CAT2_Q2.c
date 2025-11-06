/*
Name:Caleb_Weru
Regno:CT101/G/26457/25
*/
#include <stdio.h>

int main() {
    float hours, rate, grossPay, tax, netPay;

    printf("Enter hours worked in a week: ");
    scanf("%f", &hours);

    printf("Enter hourly wage: ");
    scanf("%f", &rate);

    if (hours > 40)
        grossPay = (40 * rate) + ((hours - 40) * rate * 1.5);
    else
        grossPay = hours * rate;

    if (grossPay <= 600)
        tax = 0.15 * grossPay;
    else
        tax = (0.15 * 600) + (0.20 * (grossPay - 600));

    netPay = grossPay - tax;

    printf("\nGross Pay: $%.2f", grossPay);
    printf("\nTaxes: $%.2f", tax);
    printf("\nNet Pay: $%.2f\n", netPay);

    return 0;
}