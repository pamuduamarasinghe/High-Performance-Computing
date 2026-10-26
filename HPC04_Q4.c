#include <stdio.h>
#include <pthread.h>

#define THREADS 3

int n;
unsigned long long total_fact = 1; 
pthread_mutex_t mutex;           

void *factorial_part(void *arg) {
    int tid = *(int *)arg;

    int start = tid * n / THREADS + 1;
    int end = (tid + 1) * n / THREADS;

    unsigned long long product = 1;

    for (int i = start; i <= end; i++) {
        product *= i;
    }


    pthread_mutex_lock(&mutex);
    total_fact *= product;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t threads[THREADS];
    int tid[THREADS];

    printf("Enter N: ");
    scanf("%d", &n);

    if (n < 0 || n > 20) {
        printf("Enter N between 0 and 20.\n");
        return 1;
    }

    
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < THREADS; i++) {
        tid[i] = i;

        pthread_create(&threads[i], NULL,
                       factorial_part, &tid[i]);
    }

    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

 
    pthread_mutex_destroy(&mutex);

    printf("%d! = %llu\n", n, total_fact);

    return 0;
}