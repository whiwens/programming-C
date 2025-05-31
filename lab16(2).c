#include <stdio.h>

// Выводит двоичное представление long
void print_binary_long(long n) {
    for(int i = 8*sizeof(long)-1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i % 8 == 0) printf(" "); // Разделитель для байтов
    }
    printf("\n");
}

// Выводит двоичное представление double
void print_binary_double(double x) {
    union {
        double d;
        unsigned char bytes[sizeof(double)];
    } u = {x};
    
    for(int i = sizeof(double)-1; i >= 0; i--) {
        for(int j = 7; j >= 0; j--) {
            printf("%d", (u.bytes[i] >> j) & 1);
        }
        printf(" "); // Разделитель между байтами
    }
    printf("\n");
}

int main() {
    long l;
    double d;
    
    printf("Введите long и double: ");
    scanf("%ld %lf", &l, &d);
    
    printf("\nДвоичное представление long (%ld):\n", l);
    print_binary_long(l);
    
    printf("\nДвоичное представление double (%f):\n", d);
    print_binary_double(d);
    
    return 0;
}
