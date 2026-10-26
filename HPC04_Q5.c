#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER 10

int buffer[BUFFER];
int count = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;

// Part I
void* producer(void* arg)
{
    for (int i = 0; i < BUFFER; i++)
    {
        int velocity = rand() % 71;  

        pthread_mutex_lock(&mutex);

        while (count == BUFFER)
            pthread_cond_wait(&empty, &mutex);

        buffer[count++] = velocity;

        printf("Produced velocity: %d km/h\n", velocity);

        pthread_cond_signal(&full);
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

// Part II
void* consumer(void* arg)
{
    int sum = 0;
    int velocity;

    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        pthread_mutex_lock(&mutex);

        while (count == 0)
            pthread_cond_wait(&full, &mutex);

        velocity = buffer[--count];
        sum += velocity;

        printf("Consumed velocity: %d km/h\n", velocity);

        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
    }

    double average = (double)sum / BUFFER_SIZE;

    printf("\nAverage velocity: %.2f km/h\n", average);

    pthread_exit(NULL);
}

int main()
{
    pthread_t producer_thread, consumer_thread;

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&full);
    pthread_cond_destroy(&empty);

    return 0;
}