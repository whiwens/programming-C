#include <stdio.h>
#include <stdbool.h>
#include "myLib.h"

int main()
{
    double s1, s2, s3;
    printf("vvedite 1 storonu:");
    scanf("%lf", &s1);
    printf("vvedite 2 storonu:");
    scanf("%lf", &s2);
    printf("vvedite 3 storonu:");
    scanf("%lf", &s3);
    if (valid(s1,s2,s3)){
        printf("perimeter: %lf, area: %lf", perimeter(s1, s2, s3), area(s1, s2, s3));
    } else 
        printf("invalid vvod");
    return 0;
}
