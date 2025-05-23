#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

/* Глобальная переменная для хранения имени программы */
static char* program_name;

/* Функция-обработчик сигналов с расширенным логированием */
void signal_handler(int sig) {
    const char* signal_name;
    char log_message[256];

    // Определяем имя сигнала
    switch(sig) {
        case SIGABRT: signal_name = "SIGABRT"; break;
        case SIGFPE:  signal_name = "SIGFPE";  break;
        case SIGILL:  signal_name = "SIGILL";  break;
        case SIGINT:  signal_name = "SIGINT";  break;
        case SIGSEGV: signal_name = "SIGSEGV"; break;
        case SIGTERM: signal_name = "SIGTERM"; break;
        default:     signal_name = "UNKNOWN"; break;
    }

    // Формируем строку лога с временем и PID
    snprintf(log_message, sizeof(log_message),
             "[%s] PID %d: Получен сигнал %s (%d)\n",
             program_name, getpid(), signal_name, sig);
    
    // Выводим в stderr (для корректного вывода при аварийных ситуациях)
    write(STDERR_FILENO, log_message, strlen(log_message));

    // Для некоторых сигналов добавляем дополнительную информацию
    if (sig == SIGSEGV) {
        write(STDERR_FILENO, "  Причина: нарушение доступа к памяти\n", 36);
    }
    else if (sig == SIGFPE) {
        write(STDERR_FILENO, "  Причина: ошибка арифметической операции\n", 41);
    }

    // Восстанавливаем стандартный обработчик для повторного вызова
    signal(sig, SIG_DFL);
}

/* Функция для установки всех обработчиков сигналов */
void setup_signal_handlers() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sa.sa_flags = SA_RESTART; // Перезапуск системных вызовов
    
    sigemptyset(&sa.sa_mask);
    sigaction(SIGABRT, &sa, NULL);
    sigaction(SIGFPE,  &sa, NULL);
    sigaction(SIGILL,  &sa, NULL);
    sigaction(SIGINT,  &sa, NULL);
    sigaction(SIGSEGV, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);
}

/* Функция генерации сигналов по выбору пользователя */
void generate_signal(int choice) {
    switch(choice) {
        case 1: // SIGABRT
            printf("Генерация SIGABRT через abort()\n");
            abort();
            
        case 2: // SIGFPE
            printf("Генерация SIGFPE через деление на 0\n");
            int a = 0;
            printf("%d", 1/a); // Намеренная ошибка
            break;
            
        case 3: // SIGILL
            printf("Генерация SIGILL через raise()\n");
            raise(SIGILL);
            
        case 4: // SIGINT
            printf("Генерация SIGINT через raise()\n");
            raise(SIGINT);
            
        case 5: // SIGSEGV
            printf("Генерация SIGSEGV через NULL-указатель\n");
            int *ptr = NULL;
            *ptr = 42; // Намеренная ошибка
            break;
            
        case 6: // SIGTERM
            printf("Генерация SIGTERM через raise()\n");
            raise(SIGTERM);
            
        default:
            fprintf(stderr, "Ошибка: неизвестный выбор сигнала\n");
    }
}

int main(int argc, char *argv[]) {
    program_name = argv[0]; // Сохраняем имя программы
    
    printf("=== Программа обработки сигналов ===\n");
    printf("PID процесса: %d\n", getpid());
    setup_signal_handlers();
    
    // Инструкция для пользователя
    printf("\nДоступные сигналы:\n");
    printf("1 - SIGABRT (Аварийное завершение)\n");
    printf("2 - SIGFPE  (Ошибка вычислений)\n");
    printf("3 - SIGILL  (Недопустимая инструкция)\n");
    printf("4 - SIGINT  (Прерывание)\n");
    printf("5 - SIGSEGV (Ошибка сегментации)\n");
    printf("6 - SIGTERM (Завершение)\n");
    printf("0 - Выход\n");
    
    // Основной цикл программы
    while(1) {
        printf("\nВыберите сигнал (0-6): ");
        int choice;
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n'); // Очистка буфера
            fprintf(stderr, "Ошибка ввода. Попробуйте снова.\n");
            continue;
        }
        
        if (choice == 0) {
            printf("Завершение программы.\n");
            break;
        }
        
        if (choice < 1 || choice > 6) {
            fprintf(stderr, "Неверный выбор. Введите число от 0 до 6.\n");
            continue;
        }
        
        generate_signal(choice);
    }
    
    return 0;
}
