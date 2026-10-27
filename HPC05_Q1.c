#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define Threads_num 4
#define Barrier_num 3

pthread_barrier_t barrier;

void *thread_func(void *arg){
    int id = *(int*) arg;
    printf("Thread %d started \n", id);
    pthread_barrier_wait(&barrier);
    printf("Thread %d after barierier\n",id);
    return NULL;

}


int main() {
    pthread_t threads[Threads_num];
    int ids[Threads_num];
    
    pthread_barrier_init(&barrier,NULL,Barrier_num);

    for(int i = 0 ; i <Threads_num; i++){
        ids[i] =i;
        pthread_create(&threads[i],NULL,thread_func,&ids[i]);

    }

    for(int i = 0 ; i < Threads_num; i++){
        pthread_join(threads[i],NULL);


    }

    pthread_barrier_destroy(&barrier);
    return 0 ;


}