#include <math.h>
#include <stdio.h>

double integral(double (*f)(double), double a, double b, double eps) {
    int n = 1;  // Начальное число разбиений
    double h = (b - a);
    double I_prev = 0.0;
    double I_curr =  (f(a) + f(b)) * h / 2.0;

    do {
        I_prev = I_curr;
        n *= 2;
        h = (b - a) / n;
        
        // Вычисление суммы для нечётных точек
        double sum = 0.0;
        for (int i = 1; i < n; i += 2) {
            sum += f(a + i * h);
        }
        
        I_curr = I_prev/2 + sum * h;
        
    } while (fabs(I_curr - I_prev) > eps);

    return I_curr;
}