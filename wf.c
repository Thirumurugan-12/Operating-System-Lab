#include <stdio.h>
#include <stdbool.h>

#define MEMORY_SIZE 100

// Structure to represent a memory block
typedef struct {
    int size;
    bool allocated;
} MemoryBlock;

// Function to allocate memory using Worst Fit algorithm
void worst_fit(MemoryBlock memory[], int n, int process_size) {
    int max_size = -1;
    int worst_fit_index = -1;

    for (int i = 0; i < n; i++) {
        if (!memory[i].allocated && memory[i].size >= process_size) {
            if (memory[i].size > max_size) {
                max_size = memory[i].size;
                worst_fit_index = i;
            }
        }
    }

    if (worst_fit_index != -1) {
        memory[worst_fit_index].allocated = true;
        printf("Memory allocated for process of size %d using Worst Fit\n", process_size);
    } else {
        printf("Memory allocation failed for process of size %d\n", process_size);
    }
}

int main() {
    MemoryBlock memory[10] = {{10, false}, {20, false}, {30, false}, {15, false}, {25, false},
                               {35, false}, {40, false}, {10, false}, {20, false}, {30, false}};

    // Allocate memory using Worst Fit algorithm
    worst_fit(memory, 10, 20); // Allocate memory for a process of size 20
    worst_fit(memory, 10, 30); // Allocate memory for a process of size 30

    return 0;
}
