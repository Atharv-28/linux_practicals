// SCAN Disk Scheduling in C
#include <stdio.h>
#include <stdlib.h>
#define SIZE 8
int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int abs_diff(int a, int b) {
    return a > b ? a - b : b - a;
}
int main() {
    int requests[SIZE] = {98, 183, 37, 122, 14, 124, 65, 67};
    int head, disk_size, total = 0;
    printf("Enter initial head position: ");
    scanf("%d", &head);
    printf("Enter disk size: ");
    scanf("%d", &disk_size);
    // Add head and boundary
    int arr[SIZE+2];
    for (int i = 0; i < SIZE; i++)
        arr[i] = requests[i];
    arr[SIZE] = head;
    arr[SIZE+1] = 0;
    int n = SIZE+2;
    qsort(arr, n, sizeof(int), compare);
    int pos = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == head) pos = i;
    printf("\nSCAN Order: ");
    for (int i = pos; i >= 0; i--) {
        printf("%d ", arr[i]);
        if (i != pos)
            total += abs_diff(arr[i], arr[i+1]);
    }
    for (int i = pos+1; i < n; i++) {
        printf("%d ", arr[i]);
        total += abs_diff(arr[i], arr[i-1]);
    }
    printf("\nTotal Seek Time: %d\n", total);
    return 0;
}
