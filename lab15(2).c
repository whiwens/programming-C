#include <stdio.h>

// Функция обработки цифр (1 - прямой порядок, 0 - обратный)
void d(int o) {
    int c = getchar();
    if (c == '\n' || c == EOF) return;
    if (o) { 
        putchar(c); 
        putchar(' '); 
        d(o); 
    } else { 
        d(o); 
        putchar(c); 
        putchar(' '); 
    }
}

int main() {
    // Выводим приглашение без строк
    fwrite("Введите число: ", 1, 28, stdout); // 28 байт для русского текста в UTF-8
    
    // Прямой порядок
    fwrite("Прямой порядок: ", 1, 30, stdout);
    d(1);
    
    // Сброс потока ввода
    rewind(stdin);
    while (getchar() != '\n');
    
    // Обратный порядок
    fwrite("\nОбратный порядок: ", 1, 34, stdout);
    d(0);
    
    putchar('\n');
    return 0;
}
