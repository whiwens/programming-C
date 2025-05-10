#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Структура для хранения информации о человеке
struct humen {
    char name[50];      // Имя
    char surname[50];   // Фамилия
    int birthYear;      // Год рождения
};

// Функция для сравнения людей по году рождения (для qsort)
int compareByBirthYear(const void *a, const void *b) {
    const struct humen *h1 = (const struct humen *)a;
    const struct humen *h2 = (const struct humen *)b;
    return h1->birthYear - h2->birthYear;
}

int main() {
    const int SIZE = 6;          // Количество людей
    struct humen people[SIZE];   // Массив для данных

    // Открываем файл для чтения
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }

    // Читаем данные из файла
    for (int i = 0; i < SIZE; ++i) {
        fscanf(inputFile, "%s %s %d", 
               people[i].name, 
               people[i].surname, 
               &people[i].birthYear);
    }
    fclose(inputFile);

    // Сортируем массив по году рождения
    qsort(people, SIZE, sizeof(struct humen), compareByBirthYear); //функция qsort вызывает подпрограмму compare один или несколько раз и передает указатели на два элемента массива при каждом вызове. 
// 
// Функция для сравнения людей по году рождения (для qsort) 12 строчка
    
    // Выводим отсортированные данные
    for (int i = 0; i < SIZE; ++i) {
        printf("%s %s %d\n",  // выводится текс текст число!!!!!!!
               people[i].name, 
               people[i].surname, 
               people[i].birthYear);
    }

    return 0;
}
