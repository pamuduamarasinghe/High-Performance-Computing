#include <stdlib.h>  
#include <stdio.h> 
#include <pthread.h>  // importing libaraies

#define Thread_Count 4 // setting no of threads
#define Iterations 100000 // setting  no of itterations

pthread_t threads[Thread_Count]; // Thread IDs
int shared_variable = 0;
pthread_mutex_t mutex;

void* thread_func(void*arg){
    int i ;

    for (i=0; i < Iterations; i++){   // looping for the itterations
        pthread_mutex_lock(&mutex);  // locking mutex
        shared_variable ++;
        pthread_mutex_unlock(&mutex); // releasing Mutex

    }
    return NULL;
}


int main (int argc, char** argv){
    int i;  // Loop varible

    pthread_mutex_init(&mutex,NULL);  // staring up the Mutex


    for (i = 0; i < Thread_Count ; i++){  // setting up the loop for each thread
        pthread_create(&threads[i],NULL,&thread_func,NULL); // Creating Threads

    }
    
    // Waiting threads to finish
    for (i=0; i < Thread_Count;i++){
        pthread_join(threads[i],NULL);

    }

    pthread_mutex_destroy(&mutex);  // ending mutex
    printf("The val of the Shared Varible is : %d\n",shared_variable); // Printig results



    return 0;
}