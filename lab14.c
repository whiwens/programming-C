#include <stdio.h>
#include <setjmp.h>

jmp_buf env; // Буфер для сохранения состояния

// Рекурсивная функция вычисления суммы чисел Фибоначчи
void fib_sum(int n, int a, int b, int *sum) {
    if (n <= 0) {
        longjmp(env, 1); // Выходим из всех вложенных вызовов
    }
    
    *sum += a;
    fib_sum(n - 1, b, a + b, sum); // Рекурсивный вызов
}

int main() {
    int n, sum = 0;
    
    printf("Введите количество чисел Фибоначчи для суммирования: ");
    scanf("%d", &n);
    
    if (setjmp(env) {
        // Сюда попадаем после longjmp
        printf("Сумма первых %d чисел Фибоначчи: %d\n", n, sum);
        return 0;
    }
    
    // Начинаем вычисления
    fib_sum(n, 1, 1, &sum);
    
    // Сюда не попадем, так как выход через longjmp
    return 0;
}
