#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> // Для поддержки локализации

#define MAX_RECORDS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int year;
    char gender; // 'M' для мужского пола, 'F' для женского
    double height; // Рост в метрах
} Person;

// Функция для чтения записей из файла
int read_records(const char* filename, Person records[]) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Ошибка открытия файла.\n");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%49s %d %c %lf", records[count].name, &records[count].year,
                  &records[count].gender, &records[count].height) != EOF) {
        count++;
    }
    fclose(file);
    return count;
}

// Функция для записи упорядоченных записей в файл
void write_records(const char* filename, Person records[], int count) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Ошибка открытия файла.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %c %.2f\n", records[i].name, records[i].year,
                records[i].gender, records[i].height);
    }
    fclose(file);
}

// Компараторы для сортировки по разным полям
int compare_by_year(const void* a, const void* b) {
    return ((Person*)a)->year - ((Person*)b)->year;
}

int compare_by_name(const void* a, const void* b) {
    return strcmp(((Person*)a)->name, ((Person*)b)->name);
}

int compare_by_gender(const void* a, const void* b) {
    return ((Person*)a)->gender - ((Person*)b)->gender;
}

int compare_by_height(const void* a, const void* b) {
    if (((Person*)a)->height < ((Person*)b)->height) return -1;
    if (((Person*)a)->height > ((Person*)b)->height) return 1;
    return 0;
}

// Основная программа
int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8"); // Настройка локализации для русских символов

    const char* filename = "people.txt";
    Person records[MAX_RECORDS];
    int count;

    // Чтение записей из файла
    count = read_records(filename, records);
    if (count == 0) {
        printf("Файл пуст или не существует.\n");
        return 1;
    }

    // Вывод доступных критериев сортировки
    printf("Укажите критерии сортировки (через пробел):\n");
    printf("1 - год рождения, 2 - имя/фамилия, 3 - пол, 4 - рост\n");
    printf("Пример: '1 2' для сортировки сначала по году, затем по имени.\n");

    char input[100];
    fgets(input, sizeof(input), stdin);

    // Разбор критериев сортировки
    int criteria[4];
    int num_criteria = 0;
    char* token = strtok(input, " \n");
    while (token != NULL && num_criteria < 4) {
        criteria[num_criteria++] = atoi(token);
        token = strtok(NULL, " \n");
    }

    // Многокритериальная сортировка
    qsort(records, count, sizeof(Person), [&](const void* a, const void* b) -> int {
        for (int i = 0; i < num_criteria; i++) {
            switch (criteria[i]) {
                case 1:
                    if (compare_by_year(a, b) != 0) return compare_by_year(a, b);
                    break;
                case 2:
                    if (compare_by_name(a, b) != 0) return compare_by_name(a, b);
                    break;
                case 3:
                    if (compare_by_gender(a, b) != 0) return compare_by_gender(a, b);
                    break;
                case 4:
                    if (compare_by_height(a, b) != 0) return compare_by_height(a, b);
                    break;
                default:
                    printf("Неверный критерий сортировки.\n");
                    return 0;
            }
        }
        return 0;
    });

    // Запись отсортированных записей обратно в файл
    write_records(filename, records, count);

    // Вывод результатов
    printf("Отсортированные записи:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %d %c %.2f\n", records[i].name, records[i].year,
               records[i].gender, records[i].height);
    }

    return 0;
}
