#include <stdio.h>
#include <string.h>
#include <math.h>
#include "funcs.h"
#include "root.h"
#include "integral.h"
#include "test_funcs.h"

void help_info(void)
{
    printf("Options:\n");
    printf("  -help             Show help message\n");
    printf("  -roots            Show roots\n");
    printf("  -iters            Show iterations\n");
    printf("  -test -root       Root with test functions\n");
    printf("  -test -integral   Integral with test functions\n");
}

// Основная задача
void my_task(char show_roots, char show_iters)
{
    const double eps_root = 1e-4;
    const double eps_integral = 5e-4;

    double a1 = 1.0, b1 = 2.0;     // f1 и f3
    double a2 = 3.5, b2 = 4.5;     // f2 и f3
    double a3 = 4.5, b3 = 5.5;     // f1 и f2

    double x1 = root(f1, f3, a1, b1, eps_root, show_roots, show_iters);
    double x2 = root(f2, f3, a2, b2, eps_root, show_roots, show_iters);
    double x3 = root(f1, f2, a3, b3, eps_root, show_roots, show_iters);

    double s1 = integral(f1, x1, x3, eps_integral);
    double s2 = integral(f2, x2, x3, eps_integral);
    double s3 = integral(f3, x1, x2, eps_integral);

    double total_area = s1 - s2 - s3;

    printf("Area: %lf\n", total_area);
}

void run_root_test()
{
    double (*funcs[])(double) = {t_f1, t_f2, t_f3};

    int i1, i2;
    double a, b, eps;

    printf("two function (1-3): ");
    scanf("%d %d", &i1, &i2);
    i1--; i2--;

    printf("[a, b]: ");
    scanf("%lf %lf", &a, &b);

    printf("epsilon: ");
    scanf("%lf", &eps);

    double r = root(funcs[i1], funcs[i2], a, b, eps, 1, 1);
    printf("root: %lf\n", r);
}

void run_integral_test()
{
    double (*funcs[])(double) = {t_f1, t_f2, t_f3};

    int index;
    double a, b, eps;

    printf("function (1-3): ");
    scanf("%d", &index);
    index--;

    printf("[a, b]: ");
    scanf("%lf %lf", &a, &b);

    printf("epsilon: ");
    scanf("%lf", &eps);

    double res = integral(funcs[index], a, b, eps);
    printf("integral: %lf\n", res);
}

int main(int argc, char *argv[])
{
    char show_roots = 0, show_iters = 0;
    for (int i = 1; i < argc; ++i) {
        if (!strcmp(argv[i], "-roots")) show_roots = 1;
        if (!strcmp(argv[i], "-iters")) show_iters = 1;
    }


    if (argc >= 2) {
        if (!strcmp(argv[1], "-help")) {
            help_info();
            return 0;
        }

        if (!strcmp(argv[1], "-test")) {
            char root_flag = 0, int_flag = 0;

            for (int i = 2; i < argc; ++i) {
                if (!strcmp(argv[i], "-root")) root_flag = 1;
                else if (!strcmp(argv[i], "-integral")) int_flag = 1;
            }

            if (root_flag) {
                run_root_test();
            } 
            else if (int_flag) {
                run_integral_test();
            } 
            else {
                printf("Error \n");
                help_info();
            }

            return 0;
        }
    }

    my_task(show_roots, show_iters);
    return 0;
}
