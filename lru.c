#include <stdio.h>

#define MAX 100

int main() {
    int pages[MAX], frames[MAX], recent[MAX];
    int n, frame_count;
    int i, j, k, l, flag, faults = 0;

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

    // Initialize frames and recent to -1
    for(i = 0; i < frame_count; i++) {
        frames[i] = -1;
        recent[i] = -1;
    }

    for(i = 0; i < n; i++) {
        flag = 0;

        // Check for page hit
        for(j = 0; j < frame_count; j++) {
            if(frames[j] == pages[i]) {
                flag = 1;
                recent[j] = i;
                break;
            }
        }

        // Page Fault
        if(flag == 0) {
            int lru_index = 0;
            for(j = 0; j < frame_count; j++) {
                if(frames[j] == -1) {
                    lru_index = j;
                    break;
                } else if(recent[j] < recent[lru_index]) {
                    lru_index = j;
                }
            }

            frames[lru_index] = pages[i];
            recent[lru_index] = i;
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
