#include <stdio.h>
#include <omp.h>

/*
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
    return x*x*x + 10*x + 1;
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

}*/






double simpsons_rule(double a, double b, int n, double (*f)(double))
{
    double h = (b - a) / n;

    double sum = f(a) + f(b);

    for (int i = 1; i < n; ++i)
    {
        double x = a + i * h;

        if (i % 2 == 0)
            sum += 2 * f(x);
        else
            sum += 4 * f(x);
    }

    return (h / 3.0) * sum;
}

double f(double x)
{
    return x*x*x + 10*x + 1;
}

int main()
{
    double a = 0.0;
    double b = 2.0;
    int n = 1000000;
    double result = 0.0;

    // n must be even
    if (n % 2 != 0)
    {
        printf("Number of subintervals must be even.\n");
        return 1;
    }

    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        int local_n = n / num_threads;

        // Ensure each thread gets an even number of subintervals
        int remainder = local_n % 2;
        if (remainder != 0)
            local_n--;

        double h = (b - a) / n;

        double a1 = a + id * (n / num_threads) * h;
        double b1 = a1 + local_n * h;

        double local_result =
            simpsons_rule(a1, b1, local_n, f);

        #pragma omp critical
        {
            result += local_result;
        }
    }

    printf("The approximate value of the integral with Simpson's rule is: %f\n", result);

    return 0;
}
