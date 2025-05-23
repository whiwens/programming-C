#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Обработчик сигналов
void handler(int sig) {
    const char* names[] = {"SIGABRT", "SIGFPE", "SIGILL", "SIGINT", "SIGSEGV", "SIGTERM"};
    printf("Получен %s\n", sig >= 1 && sig <= 6 ? names[sig-1] : "неизвестный сигнал");
    
    // Восстанавливаем стандартный обработчик
    signal(sig, SIG_DFL);
}

int main() {
    // Устанавливаем обработчики
    for(int i = 1; i <= 6; i++) signal(i, handler);
    
    printf("Выберите сигнал (1-6):\n"
           "1. SIGABRT\n2. SIGFPE\n3. SIGILL\n"
           "4. SIGINT\n5. SIGSEGV\n6. SIGTERM\n> ");
    
    int c;
    scanf("%d", &c);
    
    switch(c) {
        case 1: abort();
        case 2: { int x = 1/0; }
        case 3: raise(SIGILL);
        case 4: raise(SIGINT);
        case 5: { int* p = NULL; *p = 1; }
        case 6: raise(SIGTERM);
        default: printf("Неверный ввод\n");
    }
    
    return 0;
}
