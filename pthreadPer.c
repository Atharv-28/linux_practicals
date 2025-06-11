#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* threadFunction(void* arg) {
    printf("Hello from thread %d!\n", *(int*)arg);
    sleep(1);  // Simulate some work
    printf("Thread %d finished.\n", *(int*)arg);
    return NULL;
}

int main() {
    pthread_t threads[2];
    int threadIds[2] = {1, 2};

    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, threadFunction, &threadIds[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
