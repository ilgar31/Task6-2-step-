#ifndef ROOT_H
#define ROOT_H

double root(double (*f1)(double), double (*f2)(double),
           double a, double b, double eps, char print, char iter);

#endif