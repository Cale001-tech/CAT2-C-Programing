/*
Name:Caleb_Weru
Regno:CT101/G/26457/25
*/
#include <stdio.h>
#include <stdlib.h>

void writeInputFile() {
    FILE *fp;
    int numbers[10];

    fp = fopen("input.txt", "w");
    if (fp == NULL) {
        printf("Error opening input.txt for writing.\n");
        exit(1);
    }

    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
        fprintf(fp, "%d\n", numbers[i]);
    }

    fclose(fp);
    printf("Data successfully written to input.txt\n\n");
}

void processNumbers() {
    FILE *inFile, *outFile;
    int num, sum = 0, count = 0;
    float avg;

    inFile = fopen("input.txt", "r");
    if (inFile == NULL) {
        printf("Error opening input.txt for reading.\n");
        exit(1);
    }

    while (fscanf(inFile, "%d", &num) == 1) {
        sum += num;
        count++;
    }
    fclose(inFile);

    if (count == 0) {
        printf("No numbers found in input.txt.\n");
        return;
    }

    avg = (float)sum / count;

    outFile = fopen("output.txt", "w");
    if (outFile == NULL) {
        printf("Error opening output.txt for writing.\n");
        exit(1);
    }

    fprintf(outFile, "Sum = %d\n", sum);
    fprintf(outFile, "Average = %.2f\n", avg);
    fclose(outFile);

    printf("Results written to output.txt\n\n");
}

void displayFiles() {
    FILE *fp;
    char ch;

    printf("Contents of input.txt:\n");
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening input.txt.\n");
        return;
    }
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);
    fclose(fp);

    printf("\nContents of output.txt:\n");
    fp = fopen("output.txt", "r");
    if (fp == NULL) {
        printf("Error opening output.txt.\n");
        return;
    }
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);
    fclose(fp);
}

int main() {
    writeInputFile();
    processNumbers();
    displayFiles();
    
    return 0;
}