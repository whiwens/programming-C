#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols;

    srand(time(NULL));

    printf("Vvedite kolichestvo strok i stolbcov matricy (naprimer, 3 3): ");
    scanf("%d %d", &rows, &cols);

    double arr[rows][cols];
    double x1 = 0, x2 = 0;

    printf("\nMassiv %dx%d:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = (double)(rand() % 100) / 10;
            printf("%6.2lf ", arr[i][j]);
        }
        printf("\n");
    }

    if (rows == cols) {
        for (int i = 0; i < rows; i++) {
            x1 += arr[i][i]; 
            x2 += arr[i][rows - 1 - i]; 
        }
        printf("\nSumma glavnoy diagonali (X1): %.2lf\n", x1);
        printf("Summa pobochnoy diagonali (X2): %.2lf\n", x2);
    } else {
        printf("\nMatrica ne kvadratnaya, summy diagonaley ne vychislyayutsya.\n");
    }

    printf("\nVvedite kolichestvo strok i stolbcov vtoroy matricy (naprimer, 2 2): ");
    scanf("%d %d", &rows, &cols);

    int arr2[rows][cols], arr3[rows][cols];

    printf("\nMassiv %dx%d:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr2[i][j] = rand() % 100; 
            arr3[i][j] = 0;
            printf("%4d ", arr2[i][j]);
        }
        printf("\n");
    }

    if (rows == cols) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = 0; k < cols; k++) {
                    arr3[i][j] += arr2[i][k] * arr2[k][j];
                }
            }
        }

        printf("\nKvadrat matricy %dx%d:\n", rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%4d ", arr3[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nMatrica ne kvadratnaya, umnozhenie nevozmozhno.\n");
    }

    return 0;
}
