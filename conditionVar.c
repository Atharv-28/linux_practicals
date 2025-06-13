#include <stdio.h>
#include <pthread.h>
#include <unistd.h>  // <-- Add this line for sleep()

int data_ready = 0;
pthread_mutex_t mutex;
pthread_cond_t cond;

void* producer(void* arg) {
    pthread_mutex_lock(&mutex);
    printf("Producing data...\n");
    data_ready = 1;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* consumer(void* arg) {
    pthread_mutex_lock(&mutex);
    while (!data_ready) {
        pthread_cond_wait(&cond, &mutex);
    }
    printf("Data consumed.\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t p, c;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&c, NULL, consumer, NULL);
    sleep(1);  // Works now because <unistd.h> is included
    pthread_create(&p, NULL, producer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
