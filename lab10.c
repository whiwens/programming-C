#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Макрос для нахождения максимального числа в массиве
#define FIND_MAX(arr, size) \
    ({ \
        int max = arr[0]; \
        for (int i = 1; i < size; i++) { \
            if (arr[i] > max) { \
                max = arr[i]; \
            } \
        } \
        max; \
    })

int main() {
    char input[1024]; // Буфер для ввода строки
    int numbers[100]; // Массив для хранения чисел
    int count = 0;    // Количество чисел

    printf("Введите числа через пробел: ");
    fgets(input, sizeof(input), stdin); // Считываем строку с клавиатуры

    // Удаляем символ новой строки из строки
    input[strcspn(input, "\n")] = '\0';

    // Разбиваем строку на числа
    char *token = strtok(input, " ");
    while (token != NULL && count < 100) {
        numbers[count++] = atoi(token); // Преобразуем токен в число
        token = strtok(NULL, " ");      // Получаем следующий токен
    }

    // Используем макрос для нахождения максимального числа
    int max = FIND_MAX(numbers, count);

    // Выводим результат
    printf("Максимальное число: %d\n", max);

    return 0;
}
