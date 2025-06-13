// SSTF Disk Scheduling in C

#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

int abs_diff(int a, int b) {
    return a > b ? a - b : b - a;
}

int main() {
    int requests[SIZE] = {98, 183, 37, 122, 14, 124, 65, 67};
    int head, total = 0, done[SIZE] = {0};

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSSTF Order: %d ", head);
    for (int i = 0; i < SIZE; i++) {
        int min = 1e9, idx = -1;
        for (int j = 0; j < SIZE; j++) {
            if (!done[j] && abs_diff(head, requests[j]) < min) {
                min = abs_diff(head, requests[j]);
                idx = j;
            }
        }
        total += min;
        head = requests[idx];
        done[idx] = 1;
        printf("%d ", head);
    }
    printf("\nTotal Seek Time: %d\n", total);
    return 0;
}
