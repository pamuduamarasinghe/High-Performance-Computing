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

