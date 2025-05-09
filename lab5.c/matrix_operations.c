#include <stdio.h>
#include <stdlib.h>

// Функция для вычисления суммы, разности или произведения матриц
double* matrix_operation(double* matrix1, double* matrix2, int n, char operation) {
    // Выделяем память для результирующей матрицы
    double* result = (double*)malloc(n * n * sizeof(double));
    if (result == NULL) {
        printf("Ошибка выделения памяти.\n");
        exit(1);
    }

    switch (operation) {
        case '+': // Сложение матриц
            for (int i = 0; i < n * n; i++) {
                result[i] = matrix1[i] + matrix2[i];
            }
            break;

        case '-': // Вычитание матриц
            for (int i = 0; i < n * n; i++) {
                result[i] = matrix1[i] - matrix2[i];
            }
            break;

        case '*': // Умножение матриц
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    result[i * n + j] = 0;
                    for (int k = 0; k < n; k++) {
                        result[i * n + j] += matrix1[i * n + k] * matrix2[k * n + j];
                    }
                }
            }
            break;

        default:
            printf("Неверная операция.\n");
            free(result);
            exit(1);
    }

    return result;
}
