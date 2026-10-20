#include <stdlib.h>  
#include <stdio.h> 
#include <time.h>
#include <pthread.h>  // importing libraries

#define Thread_Count 4  // setting no of threads
#define total 1000000   // setting total points

double global = 0.0;  // variable to get final count
pthread_mutex_t mutex;

// Setting up Monte Carlo
void* Monte_carlo(void* thread_id) {
    int tid = *((int*)thread_id);
    long points = total / Thread_Count;
    long local = 0;  // counter for thread


    srand((unsigned int)time(NULL) + tid); // Random number generator

    for (long i = 0; i < points; i++) {
    
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;  // Random vals for x and y 
        double dist = x * x + y * y;                  // value for distance squared
        
        if (dist <= 1.0) {
            local++;
        }
    }
    
    pthread_mutex_lock(&mutex);   // locking mutex
    global += (double)local;      // update global counter
    pthread_mutex_unlock(&mutex); // releasing Mutex 
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[Thread_Count]; // Thread IDs
    int thread_ids[Thread_Count];

    pthread_mutex_init(&mutex, NULL);  // starting up the Mutex

    for (int i = 0; i < Thread_Count; i++) {  // setting up the loop for each thread
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, &Monte_carlo, &thread_ids[i]); // Creating Threads
    }
    
    // Waiting for threads to finish
    for (int i = 0; i < Thread_Count; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);  // ending mutex

    double pi = 4.0 * (global / total);
    
    // print results
    printf("The val of Pi is : %f\n", pi); 

    return 0;
}