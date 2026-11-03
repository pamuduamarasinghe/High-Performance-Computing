#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define Threads_num 4

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
