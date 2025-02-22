#include <stdio.h>

int main() {
    
    double arr[3][3];
    double x1 = 0, x2 = 0;

    printf("Vvedite elementi massiva 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Vvedite A[%d][%d]: ", i, j);
            scanf("%lf", &arr[i][j]);
        }
    }

    printf("\nMassiv 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%6.2lf ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++) {
        x1 += arr[i][i]; 
        x2 += arr[i][2 - i]; 
    }
    printf("\nSumma glavnoy diagonali (X1): %.2lf\n", x1);
    printf("Summa pobochnoy diagonali (X2): %.2lf\n", x2);

    int arr2[2][2], arr3[2][2] = {0};

    printf("\nVvedite elementi massiva 2x2:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Vvedite B[%d][%d]: ", i, j);
            scanf("%d", &arr2[i][j]);
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                arr3[i][j] += arr2[i][k] * arr2[k][j];
            }
        }
    }

    printf("\nKvadrat matricy 2x2:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%4d ", arr3[i][j]);
        }
        printf("\n");
    }

    return 0;
}
