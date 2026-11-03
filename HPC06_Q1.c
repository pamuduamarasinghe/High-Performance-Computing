#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define Threads_num 4
/*

// OpenMP to create multiple threads

void thread_func(void){
    int id = omp_get_thread_num();
    int thread_count = omp_get_num_threads();
    printf("Thread %d of %d \n", id, thread_count);
}

int main(){
    #pragma omp parallel num_threads(Threads_num)
    {
        thread_func();
    }
    return 0;
}
*/

/*
//Sum of first n integers using OpenMP
int main(){
    int n = 100;
    int sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for(int i = 1; i <= n; i++){
        sum += i;
    }

    printf("Sum of first %d integers is: %d\n", n, sum);
    return 0;
}
*/


/*
// Error Checking in OpenMP
#ifdef _OPENMP
#include <omp.h>
#endif

#define ARRAY_SIZE 1000000

int array[ARRAY_SIZE];
	
int main() {
    long long sum = 0;


    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = i;
    }

    #ifdef _OPENMP
    #pragma omp parallel for reduction(+:sum)
    #endif
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        sum += array[i];
    }

    printf("Sum: %lld\n", sum);

    return 0;
}
*/

// Sum of the first N with multiple threads using OpenMP
int main() {
    int n=100;
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