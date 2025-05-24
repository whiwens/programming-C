#include <stdio.h>
#include <math.h>

// Функция проверки, является ли число нулем (включая 0000)
int is_zero(int n) {
    return n == 0;
}

// Функция подсчета количества цифр в числе
int count_digits(int n) {
    if (n == 0) return 1;
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

// Функция вывода цифр в прямом порядке
void print_forward(int n) {
    int num_digits = count_digits(n);
    for (int i = num_digits - 1; i >= 0; i--) {
        int digit = (n / (int)pow(10, i)) % 10;
        printf("%d ", digit);
    }
}

// Функция вывода цифр в обратном порядке
void print_reverse(int n) {
    while (n != 0) {
        printf("%d ", n % 10);
        n /= 10;
    }
}

int main() {
    int N;
    printf("Введите число: ");
    scanf("%d", &N);
    
    if (is_zero(N)) {
        return 0;  // Завершаем программу без вывода
    }
    
    printf("Цифры в прямом порядке: ");
    print_forward(N);
    
    printf("\nЦифры в обратном порядке: ");
    print_reverse(N);
    
    printf("\n");
    return 0;
}
