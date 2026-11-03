#include <stdio.h>
#include <omp.h>

double trapezoidal_rule(double a, double b, int n, double (*f)(double))
{
    double h = (b - a)/n;
    double sum = (f(a)+f(b))/2.0;

    for (int i = 1; i<n; ++i) {
        double x = a + i*h;
        sum += f(x);
    }

    return h * sum;
}

double f(double x)
{
    return 2*x*x + 10*x + 6;
}

int main()
{
    double a = 0.0;
    double b = 2.0;
    int n = 1000000;
    double result = 0.0;

    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        int local_n = n / num_threads;
        double h = (b - a) / num_threads;

        double a1 = a+id*h;
        double b1 = a+(id + 1)*h;

        double local_result =
            trapezoidal_rule(a1, b1, local_n, f);

        #pragma omp critical
        {
            result += local_result;
        }
    }

    printf("The approximate value of the integral is: %f\n", result);

    return 0;
}