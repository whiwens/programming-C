#include <stdio.h>
#include <stdlib.h>
#include "matrix_operations.h"

// Функция для ввода элементов матрицы
void input_matrix(double* matrix, int n, const char* name) {
    printf("Введите элементы матрицы %s (%d x %d):\n", name, n, n);
    for (int i = 0; i < n * n; i++) {
        scanf("%lf", &matrix[i]);
    }
}

// Функция для вывода матрицы
void print_matrix(double* matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", matrix[i * n + j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    char operation;

    // Ввод размерности матриц
    printf("Введите размерность матриц (n): ");
    scanf("%d", &n);

    // Выделение памяти для матриц
    double* matrix1 = (double*)malloc(n * n * sizeof(double));
    double* matrix2 = (double*)malloc(n * n * sizeof(double));

    if (matrix1 == NULL || matrix2 == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    // Ввод элементов матриц
    input_matrix(matrix1, n, "A");
    input_matrix(matrix2, n, "B");

    // Ввод операции
    printf("Введите операцию (+, -, *): ");
    scanf(" %c", &operation);

    // Выполнение операции
    double* result = matrix_operation(matrix1, matrix2, n, operation);

    // Вывод результата
    printf("Результат:\n");
    print_matrix(result, n);

    // Освобождение памяти
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
