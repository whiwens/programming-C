#include <stdio.h>
#include <stdarg.h> // Необходимо для работы с переменным числом аргументов
#include <limits.h> // Для констант INT_MIN и INT_MAX

// Функция вычисления суммы
int sum(int count, ...) {  // count - количество аргументов, ... - переменное число аргументов
    va_list args;          // Объявляем список аргументов
    va_start(args, count); // Инициализируем список (args - куда сохранять, count - с какого аргумента начинать)
    
    int total = 0;         // Переменная для накопления суммы
    for(int i = 0; i < count; i++) {  // Цикл по всем аргументам
        total += va_arg(args, int);    // Получаем очередной аргумент типа int и добавляем к сумме
    }
    
    va_end(args);          // Завершаем работу с переменными аргументами
    return total;         // Возвращаем результат
}

// Функция нахождения максимума
int max(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int current_max = INT_MIN;  // Начинаем с минимально возможного значения int
    for(int i = 0; i < count; i++) {
        int num = va_arg(args, int);  // Получаем очередное число
        if(num > current_max) {       // Если оно больше текущего максимума
            current_max = num;        // Обновляем максимум
        }
    }
    
    va_end(args);
    return current_max;
}

// Функция нахождения минимума
int min(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int current_min = INT_MAX;  // Начинаем с максимально возможного значения int
    for(int i = 0; i < count; i++) {
        int num = va_arg(args, int);  // Получаем очередное число
        if(num < current_min) {       // Если оно меньше текущего минимума
            current_min = num;        // Обновляем минимум
        }
    }
    
    va_end(args);
    return current_min;
}

// Функция вычисления среднего арифметического
double average(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int total = 0;
    for(int i = 0; i < count; i++) {
        total += va_arg(args, int);  // Считаем сумму всех чисел
    }
    
    va_end(args);
    return (double)total / count;    // Возвращаем среднее (приводим к double для точности)
}

int main() {
    // Примеры использования функций
    printf("Sum: %d\n", sum(3, 10, 20, 30));
    printf("Max: %d\n", max(4, 5, 2, 8, 1));
    printf("Min: %d\n", min(4, 5, 2, 8, 1));
    printf("Average: %.2f\n", average(3, 10, 20, 30));
    
    return 0;
}
