#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int a[] = {29, 10, 14, 37, 13, 5, 6, 89, 1, 0};
#define N (sizeof(a)/sizeof(a[0]))

typedef struct { int l, h; } Range;

void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }

int part(int l, int h) {
    int p = a[h], i = l - 1, j;
    for (j = l; j < h; j++)
        if (a[j] < p)
            swap(&a[++i], &a[j]);
    swap(&a[i + 1], &a[h]);
    return i + 1;
}

void* qsortT(void* arg) {
    Range *r = (Range*)arg;
    int l = r->l, h = r->h;
    free(arg);  // Free allocated memory

    if (l < h) {
        int p = part(l, h);
        Range *r1 = malloc(sizeof(Range));
        Range *r2 = malloc(sizeof(Range));
        r1->l = l; r1->h = p - 1;
        r2->l = p + 1; r2->h = h;
        
        pthread_t t1, t2;
        pthread_create(&t1, NULL, qsortT, r1);
        pthread_create(&t2, NULL, qsortT, r2);
        
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
    }
    
    return NULL;
}

int main() {
    Range *r = malloc(sizeof(Range));
    r->l = 0; r->h = N - 1;
    
    pthread_t t;
    pthread_create(&t, NULL, qsortT, r);
    pthread_join(t, NULL);
    
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    
    puts("");
    return 0;
}
