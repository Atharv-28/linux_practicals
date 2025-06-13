#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define SIZE 5
int buffer[SIZE];
int in = 0, out = 0;
sem_t empty, full;
pthread_mutex_t mutex;
// Producer thread function
void* producer(void* arg) {
    for (int i = 0; i < 10; i++) {
        sem_wait(&empty);              // wait if buffer is full
        pthread_mutex_lock(&mutex);    // acquire mutex lock

        buffer[in] = i;
        printf("Produced: %d\n", i);
        in = (in + 1) % SIZE;

        pthread_mutex_unlock(&mutex);  // release mutex lock
        sem_post(&full);               // signal that buffer has new item
        sleep(1);
    }
    return NULL;
}
// Consumer thread function
void* consumer(void* arg) {
    for (int i = 0; i < 10; i++) {
        sem_wait(&full);               // wait if buffer is empty
        pthread_mutex_lock(&mutex);    // acquire mutex lock

        int item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % SIZE;

        pthread_mutex_unlock(&mutex);  // release mutex lock
        sem_post(&empty);              // signal that buffer has empty slot
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t p, c;

    sem_init(&empty, 0, SIZE);  // buffer empty slots
    sem_init(&full, 0, 0);      // buffer full slots
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
