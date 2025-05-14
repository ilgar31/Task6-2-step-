#include <stdio.h>
#include <math.h>
#include "root.h"

// Функция для определения знака (безопасная обработка нуля)
static int sign(double x) {
    return (x > 0) - (x < 0);
}

// Функция нахождения корня методом деления отрезка пополам
double root(double (*f1)(double), double (*f2)(double),
            double a, double b, double eps, char print, char iter)
{
    double fa = f1(a) - f2(a);
    double fb = f1(b) - f2(b);
    double c, fc;
    int iterations = 1;


    // Проверка условий применимости метода
    if (sign(fa) * sign(fb) >= 0) {
        return NAN; // Нет корня или корень на границе
    }
    
    // Основной цикл метода
    do {
        iterations++;
        c = (a + b) / 2.0;
        fc = f1(c) - f2(c);
        
        // Проверка на точное попадание в корень
        if (fc == 0.0) {
            return c;
        }
        
        // Выбор нового интервала
        if (sign(fa) * sign(fc) < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
        
        // Критерий остановки: длина интервала меньше eps
    } while (fabs(b - a) >= eps);

    if (print) printf("Solution: %lf\n", c);
    if (iter) printf("Number of iterations: %d\n", iterations);
    
    // Возвращаем середину последнего интервала
    return (a + b) / 2.0;
}
