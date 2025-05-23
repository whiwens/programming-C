#include <stdio.h>
#include <stddef.h>

int count_bits_long(long num) {          // Функция подсчёта битов в long
    int count = 0;                       // Счётчик битов
    for(size_t i=0; i<sizeof(num)*8; i++) // Цикл по всем битам (8*размер типа)
        if(num & (1L << i)) count++;     // Если бит установлен, увеличиваем счётчик
    return count;                        // Возвращаем результат
}

int count_bits_double(double num) {      // Функция подсчёта битов в double
    int count = 0;                       // Счётчик битов
    unsigned char* bytes = (unsigned char*)# // Преобразуем в массив байтов
    for(size_t i=0; i<sizeof(num); i++)   // Цикл по всем байтам числа
        for(int j=0; j<8; j++)           // Цикл по битам в каждом байте
            if(bytes[i] & (1 << j))      // Проверка установки бита
                count++;                  // Увеличиваем счётчик
    return count;                        // Возвращаем результат
}

int main() {
    long l; double d;                    // Переменные для хранения чисел
    printf("Введите long и double: ");   // Приглашение к вводу
    scanf("%ld %lf", &l, &d);           // Чтение двух чисел
    printf("Битов в long: %d\n"         // Вывод результатов
           "Битов в double: %d\n", 
           count_bits_long(l), 
           count_bits_double(d));
    return 0;
}
