#include <stdio.h>

#define MAX 100

int main() {
    int pages[MAX], frames[MAX];
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

    // Initialize frames to -1 (empty)
    for(i = 0; i < frame_count; i++) {
        frames[i] = -1;
    }

    for(i = 0; i < n; i++) {
        flag = 0;

        // Check if page is already in a frame
        for(j = 0; j < frame_count; j++) {
            if(frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        // Page Fault
        if(flag == 0) {
            int replace_index = -1, farthest = -1;

            for(j = 0; j < frame_count; j++) {
                int found = 0;
                for(k = i + 1; k < n; k++) {
                    if(frames[j] == pages[k]) {
                        if(k > farthest) {
                            farthest = k;
                            replace_index = j;
                        }
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    replace_index = j;
                    break;
                }
            }

            if(replace_index == -1) replace_index = 0;

            frames[replace_index] = pages[i];
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
