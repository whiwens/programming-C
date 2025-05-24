#include <stdio.h>
#include <setjmp.h>

jmp_buf env;

// Рекурсивная функция вычисления суммы чисел Фибоначчи
void fib_sum(int n, unsigned long long a, unsigned long long b, unsigned long long *sum) {
    if (n <= 0) {
        longjmp(env, 1);
    }
    
    *sum += a;
    fib_sum(n - 1, b, a + b, sum);
}

int main() {
    int n;
    unsigned long long sum = 0;
    
    printf("Введите количество чисел Фибоначчи для суммирования: ");
    scanf("%d", &n);
    
    if (setjmp(env)) {
        printf("Сумма первых %d чисел Фибоначчи: %llu\n", n, sum);
        return 0;
    }
    
    fib_sum(n, 1, 1, &sum);
    
    return 0;
}
