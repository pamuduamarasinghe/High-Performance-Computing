#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NUM_PARTICLES 4

typedef struct {
    double x;
    double y;
    double z;
} particle;

particle particles[NUM_PARTICLES];

pthread_rwlock_t rwlock;

void *detector(void *arg)
{
    while (1) {
        pthread_rwlock_wrlock(&rwlock);

        for (int i = 0; i < NUM_PARTICLES; i++) {
            particles[i].x = (double)rand() / RAND_MAX * 10;
            particles[i].y = (double)rand() / RAND_MAX * 10;
            particles[i].z = (double)rand() / RAND_MAX * 10;
        }

        pthread_rwlock_unlock(&rwlock);
        break;
    }

    return NULL;
}

void *reader(void *arg)
{
    pthread_rwlock_rdlock(&rwlock);

    double min_distance = 1000000;
    int p1 = 0, p2 = 1;

    for (int i = 0; i < NUM_PARTICLES; i++) {
        for (int j = i + 1; j < NUM_PARTICLES; j++) {
            double dx = particles[i].x - particles[j].x;
            double dy = particles[i].y - particles[j].y;
            double dz = particles[i].z - particles[j].z;

            double distance = sqrt(dx*dx + dy*dy + dz*dz);

            if (distance < min_distance) {
                min_distance = distance;
                p1 = i;
                p2 = j;
            }
        }
    }

    printf("Particle %d and Particle %d have the minimum distance \n",
           p1 + 1, p2 + 1);
    printf("min distance = %f\n", min_distance);

    pthread_rwlock_unlock(&rwlock);

    return NULL;
}

int main()
{
    pthread_t detector_thread, reader_thread;

    srand( time(NULL) );

    pthread_rwlock_init(&rwlock, NULL);
    pthread_create(&detector_thread, NULL, detector, NULL);
    pthread_join(detector_thread, NULL);

    pthread_create(&reader_thread, NULL, reader, NULL);
    pthread_join(reader_thread, NULL);

    pthread_rwlock_destroy(&rwlock);

    return 0;
}