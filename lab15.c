#include <stdio.h>
#include <math.h>

// Функция для подсчета количества цифр в числе
int count_digits(int n) {
    if (n < 10) return 1;
    return 1 + count_digits(n / 10);
}

// Функция для вывода цифр в прямом порядке
void print_forward(int n) {
    if (n < 10) {
        printf("%d ", n);
        return;
    }
    int power = pow(10, count_digits(n) - 1);
    printf("%d ", n / power);
    print_forward(n % power);
}

// Функция для вывода цифр в обратном порядке
void print_reverse(int n) {
    if (n < 10) {
        printf("%d ", n);
        return;
    }
    printf("%d ", n % 10);
    print_reverse(n / 10);
}

int main() {
    int N;
    printf("Введите натуральное число N: ");
    scanf("%d", &N);
    
    printf("Цифры в прямом порядке: ");
    print_forward(N);
    
    printf("\nЦифры в обратном порядке: ");
    print_reverse(N);
    
    printf("\n");
    return 0;
}
