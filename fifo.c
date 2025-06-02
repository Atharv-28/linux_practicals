#include <stdio.h>

#define MAX 100
int main() {
    int pages[MAX], frames[MAX];
    int n, frame_count;
    int i, j, k, flag, faults = 0;
    int front = 0; // Points to the oldest page

    // Input page reference string
    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Input number of frames
    printf("Enter number of frames: ");
    scanf("%d", &frame_count);

    // Initialize frames to -1 (empty)
    for(i = 0; i < frame_count; i++) {
        frames[i] = -1;
    }

    // FIFO Page Replacement Logic
    for(i = 0; i < n; i++) {
        flag = 0;

        // Check if page is already in a frame
        for(j = 0; j < frame_count; j++) {
            if(frames[j] == pages[i]) {
                flag = 1; // Page hit
                break;
            }
        }
        // If not found (page fault), replace using FIFO
        if(flag == 0) {
            frames[front] = pages[i]; // Replace oldest
            front = (front + 1) % frame_count; // Move front pointer
            faults++;

            // Print current frame state
            printf("Page %d -> [", pages[i]);
            for(k = 0; k < frame_count; k++) {
                if(frames[k] != -1)
                    printf("%d", frames[k]);
                else
                    printf(" ");
                if(k != frame_count - 1)
                    printf(" ");
            }
            printf("]\n");
        }
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}
