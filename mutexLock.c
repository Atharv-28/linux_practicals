#include <stdio.h>
#include <pthread.h>

#define N 1000000

int counter = 0;
pthread_mutex_t lock;

// Thread function
void* increment(void* arg) {
    for (int i = 0; i < N; i++) {
        pthread_mutex_lock(&lock);  // acquire lock
        counter++;
        pthread_mutex_unlock(&lock);  // release lock
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);
    printf("Final Counter: %d\n", counter);

    return 0;
}
