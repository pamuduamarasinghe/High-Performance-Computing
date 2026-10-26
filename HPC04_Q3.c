#include <stdio.h>
#include <pthread.h>

#define THREADS 3

int n;
unsigned long long total_sum = 0; 
pthread_mutex_t mutex;           

void *sum_part(void *arg) {
    int tid = *(int *)arg;

    int start = tid * n / THREADS + 1;
    int end = (tid + 1) * n / THREADS;

    unsigned long long partial_sum = 0; 

    for (int i = start; i <= end; i++) {
        partial_sum += i; 
    }


    pthread_mutex_lock(&mutex);
    total_sum += partial_sum;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t threads[THREADS];
    int tid[THREADS];

    printf("Enter N: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Enter a non-negative N.\n");
        return 1;
    }

 
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        perror("Mutex init failed");
        return 1;
    }

    for (int i = 0; i < THREADS; i++) {
        tid[i] = i;
        pthread_create(&threads[i], NULL, sum_part, &tid[i]);
    }

    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

   
    pthread_mutex_destroy(&mutex);

    printf("Sum of first %d integers = %llu\n", n, total_sum);

    return 0;
}
