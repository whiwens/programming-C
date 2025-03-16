#include <math.h>

double perimeter(double s1, double s2, double s3){
    return s1 + s2 + s3;
}

double area(double s1, double s2, double s3){
    double p = perimeter(s1, s2, s3) / 2.0;
    return sqrt(p * (p - s1) * (p - s2) * (p - s3));
}

bool valid(double s1, double s2, double s3){
    return s1+s2>s3 && s2+s3>s1 && s3+s1>s2;
}
