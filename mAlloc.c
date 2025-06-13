#include <stdio.h>
#define BLOCKS 5
#define PROCESSES 4
// Function to display allocation result
void display(int allocation[], int processSize[]) {
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < PROCESSES; i++) {
        printf("   %d\t\t   %d\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i]+1);
        else
            printf("Not Allocated\n");
    }
}
// First Fit Algorithm
void firstFit(int blockSize[], int processSize[]) {
    int allocation[PROCESSES];
    for (int i = 0; i < PROCESSES; i++)
        allocation[i] = -1; // initially no allocation
    for (int i = 0; i < PROCESSES; i++) {
        for (int j = 0; j < BLOCKS; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    printf("\nFirst Fit Allocation:\n");
    display(allocation, processSize);
}
// Best Fit Algorithm
void bestFit(int blockSize[], int processSize[]) {
    int allocation[PROCESSES];
    for (int i = 0; i < PROCESSES; i++)
        allocation[i] = -1;
    for (int i = 0; i < PROCESSES; i++) {
        int bestIdx = -1;
        for (int j = 0; j < BLOCKS; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }
    printf("\nBest Fit Allocation:\n");
    display(allocation, processSize);
}
// Worst Fit Algorithm
void worstFit(int blockSize[], int processSize[]) {
    int allocation[PROCESSES];
    for (int i = 0; i < PROCESSES; i++)
        allocation[i] = -1;

    for (int i = 0; i < PROCESSES; i++) {
        int worstIdx = -1;
        for (int j = 0; j < BLOCKS; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }
    printf("\nWorst Fit Allocation:\n");
    display(allocation, processSize);
}
int main() {
    int blockSize[BLOCKS] = {100, 500, 200, 300, 600};
    int processSize[PROCESSES] = {212, 417, 112, 426};
    int choice;
    printf("Memory Allocation Methods:\n1. First Fit\n2. Best Fit\n3. Worst Fit\nEnter your choice: ");
    scanf("%d", &choice);
    int tempBlock[BLOCKS];
    for (int i = 0; i < BLOCKS; i++)
        tempBlock[i] = blockSize[i]; // copy original block sizes
    if (choice == 1)
        firstFit(tempBlock, processSize);
    else if (choice == 2)
        bestFit(tempBlock, processSize);
    else if (choice == 3)
        worstFit(tempBlock, processSize);
    else
        printf("Invalid choice\n");
    return 0;
}
