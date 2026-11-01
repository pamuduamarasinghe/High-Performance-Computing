#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_FORCE 100
#define BUFFER_DIS 50
#define SAMPLES 50  // Total readings to process

float buffer_force[BUFFER_FORCE];
float buffer_dis[BUFFER_DIS];

int count_force = 0, in_force = 0, out_force = 0;
int count_dis = 0, in_dis = 0, out_dis = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;

// Part I
void* producer(void* arg)
{
    // Force Data
    for (int i = 0; i < SAMPLES; i++)
    {
        float force = (float)(rand() % 100 + 1); 

        pthread_mutex_lock(&mutex);

        while (count_force == BUFFER_FORCE)
            pthread_cond_wait(&empty, &mutex);

        buffer_force[in_force] = force;
        in_force = (in_force + 1) % BUFFER_FORCE;
        count_force++;

        printf("Produced Force: %.2f N\n", force);

        pthread_cond_broadcast(&full);
        pthread_mutex_unlock(&mutex);
    }

    // Displacement data
    for (int i = 0; i < SAMPLES; i++)
    {
        float dis = (float)(rand() % 10 + 1); 

        pthread_mutex_lock(&mutex);

        while (count_dis == BUFFER_DIS)
            pthread_cond_wait(&empty, &mutex);

        buffer_dis[in_dis] = dis;
        in_dis = (in_dis + 1) % BUFFER_DIS;
        count_dis++;

        printf("Produced Displacement: %.2f m\n", dis);

        pthread_cond_broadcast(&full);
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

// Part II
void* consumer(void* arg)
{
    float sum = 0;
    float work;

    for (int i = 0; i < SAMPLES; i++)
    {
        pthread_mutex_lock(&mutex);

        // Wait until both buffers have at least one reading
        while (count_force == 0 || count_dis == 0)
            pthread_cond_wait(&full, &mutex);

        // Consume Force
        float force = buffer_force[out_force];
        out_force = (out_force + 1) % BUFFER_FORCE;
        count_force--;

        // Consume Displacement
        float dis = buffer_dis[out_dis];
        out_dis = (out_dis + 1) % BUFFER_DIS;
        count_dis--;

        // Work Done
        work = force * dis;
        sum += work;

        printf("Consumed Work Done: %.2f J\n", work);

        pthread_cond_broadcast(&empty);
        pthread_mutex_unlock(&mutex);
    }

    double average = (double)sum / SAMPLES;

    printf("\nAverage Work: %.2f J\n", average);

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