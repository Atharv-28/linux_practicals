// FCFS Disk Scheduling in C

#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

int abs_diff(int a, int b) {
    return a > b ? a - b : b - a;
}

int main() {
    int requests[SIZE] = {98, 183, 37, 122, 14, 124, 65, 67};
    int head, total = 0;

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nFCFS Order: %d ", head);
    for (int i = 0; i < SIZE; i++) {
        total += abs_diff(head, requests[i]);
        head = requests[i];
        printf("%d ", head);
    }
    printf("\nTotal Seek Time: %d\n", total);
    return 0;
}
