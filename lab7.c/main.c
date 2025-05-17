#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Структура для хранения информации о человеке
struct humen {
    char name[50];      // Имя
    char surname[50];   // Фамилия
    int birthYear;      // Год рождения
};

// Функция для обмена двух структур humen
void swap(struct humen *a, struct humen *b) {
    struct humen temp = *a;
    *a = *b;
    *b = temp;
}

// Пузырьковая сортировка структур по году рождения
void bubbleSort(struct humen arr[], int n) {
    // Внешний цикл - проходит по всем элементам
    for (int i = 0; i < n-1; i++) {
        
        // Внутренний цикл - сравниваем пары элементов
        for (int j = 0; j < n-i-1; j++) {
            
            // Если текущий элемент больше следующего
            if (arr[j].birthYear > arr[j+1].birthYear) {
                // Меняем их местами
                struct humen temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
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

    // Сортируем массив пузырьковой сортировкой
    bubbleSort(people, SIZE);

    // Выводим отсортированные данные
    for (int i = 0; i < SIZE; ++i) {
        printf("%s %s %d\n",  
               people[i].name, 
               people[i].surname, 
               people[i].birthYear);
    }

    return 0;
}
