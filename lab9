#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Функция для вычисления результата выражения
double calculate(char *expression) {
    char *token; // Указатель на токен
    double result = 0.0; // Результат вычислений
    double number; // Текущее число
    char operator = '+'; // Оператор (по умолчанию +)

    // Разбиваем строку на токены с помощью strtok
    token = strtok(expression, " \t\n+-");
    while (token != NULL) {
        // Преобразуем токен в число
        number = atof(token);

        // Выполняем операцию в зависимости от текущего оператора
        if (operator == '+') {
            result += number;
        } else if (operator == '-') {
            result -= number;
        }

        // Определяем следующий оператор
        while (*expression && !isdigit(*expression) && *expression != '-' && *expression != '+') {
            expression++;
        }
        operator = *expression;

        // Получаем следующий токен
        token = strtok(NULL, " \t\n+-");
    }

    return result;
}

int main() {
    char input[1024]; // Буфер для ввода выражения

    printf("Введите выражение: ");
    fgets(input, sizeof(input), stdin); // Считываем строку с клавиатуры

    // Удаляем символ новой строки из строки
    input[strcspn(input, "\n")] = '\0';

    // Вычисляем результат
    double result = calculate(input);

    // Выводим результат
    printf("Результат: %.2f\n", result);

    return 0;
}
