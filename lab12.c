#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Функция для определения дня недели по дате (0 - воскресенье, 1 - понедельник, ..., 6 - суббота)
int get_day_of_week(int year, int month, int day) {
    if (month <= 2) {
        month += 12;
        year -= 1;
    }
    int k = year % 100;
    int j = year / 100;
    int h = (day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    return (h + 6) % 7; // Преобразование в диапазон 0-6
}

// Функция для проверки високосного года
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Функция для получения количества дней в месяце
int days_in_month(int year, int month) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    return days[month - 1];
}

// Функция для вывода календаря за месяц
void print_month_calendar(int year, int month) {
    const char *days[] = {"Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс"};
    int days_in_m = days_in_month(year, month);

    printf("\nКалендарь за %d.%d:\n", year, month);
    for (int i = 0; i < 7; i++) {
        printf("%s ", days[i]);
    }
    printf("\n");

    int start_day = get_day_of_week(year, month, 1);
    for (int i = 0; i < start_day; i++) {
        printf("   ");
    }

    for (int day = 1; day <= days_in_m; day++) {
        printf("%2d ", day);
        if ((start_day + day) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// Функция для вывода календаря за год
void print_year_calendar(int year) {
    for (int month = 1; month <= 12; month++) {
        print_month_calendar(year, month);
        printf("\n");
    }
}

// Функция для вывода текущей даты
void print_current_date() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Текущая дата: %d.%02d.%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

int main() {
    char input[20];
    printf("Введите дату (гггг.мм.дд, гггг.мм, гггг, now): ");
    scanf("%s", input);

    if (strcmp(input, "now") == 0) {
        print_current_date();
    } else if (strlen(input) == 4) {
        // Формат: гггг (год)
        int year = atoi(input);
        print_year_calendar(year);
    } else if (strlen(input) == 7) {
        // Формат: гггг.мм (месяц)
        int year, month;
        sscanf(input, "%d.%d", &year, &month);
        print_month_calendar(year, month);
    } else if (strlen(input) == 10) {
        // Формат: гггг.мм.дд (день)
        int year, month, day;
        sscanf(input, "%d.%d.%d", &year, &month, &day);
        const char *weekdays[] = {"Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота"};
        int weekday = get_day_of_week(year, month, day);
        printf("День недели: %s\n", weekdays[weekday]);
    } else {
        printf("Неверный формат ввода.\n");
    }

    return 0;
}
