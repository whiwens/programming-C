#include <stdio.h>
#include <string.h>

int main() {
    char s[81];
    printf("Введите строку: ");
    fgets(s, 81, stdin);

    if (strlen(s) > 80) {
        printf("Ошибка: строка слишком длинная.\n");
        return 1;
    }

    for (int i = 0; s[i]; i++)
        if (s[i] == 'a') s[i] = 'A';
        else if (s[i] == 'b') s[i] = 'B';

    printf("Результат: %s", s);
    return 0;
}
