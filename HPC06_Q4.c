#include <stdio.h>
#include <omp.h>
/*
int main() {
    int n=1000
    ;
    int sum = 0;

    #pragma omp parallel
    {
        int thread_sum = 0;
        #pragma omp for

        for (int i = 1; i <= n; i++) {
            thread_sum += i;
        }

        #pragma omp critical
        {
            sum += thread_sum;
        }

    
    }

    printf("Sum of first %d integers is: %d\n", n, sum);
}
*/

/* // without OpenMP 
#include <stdio.h>

int main()
{
    int n = 1000;
    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }

    printf("Sum of first %d integers without OpenMP is: %d\n", n, sum);

    return 0;
}
*/

//factorial calculation using OpenMP

#include <stdio.h>
#include <omp.h>

int main()
{
    int n = 10;
    long long int fact = 1;

    #pragma omp parallel
    {
        long long int thread_fact = 1;

        #pragma omp for
        for (int i = 1; i <= n; i++)
        {
            thread_fact *= i;
        }

        #pragma omp critical
        {
            fact *= thread_fact;
        }
    }

    printf("Factorial of %d is: %lld\n", n, fact);

    return 0;
}
