#include <stdio.h>
#include <stdbool.h>

#define MEMORY_SIZE 100

// Structure to represent a memory block
typedef struct {
    int size;
    bool allocated;
} MemoryBlock;

// Function to allocate memory using Best Fit algorithm
void best_fit(MemoryBlock memory[], int n, int process_size) {
    int min_size = MEMORY_SIZE + 1;
    int best_fit_index = -1;

    for (int i = 0; i < n; i++) {
        if (!memory[i].allocated && memory[i].size >= process_size) {
            if (memory[i].size < min_size) {
                min_size = memory[i].size;
                best_fit_index = i;
            }
        }
    }

    if (best_fit_index != -1) {
        memory[best_fit_index].allocated = true;
        printf("Memory allocated for process of size %d using Best Fit\n", process_size);
    } else {
        printf("Memory allocation failed for process of size %d\n", process_size);
    }
}

int main() {
    MemoryBlock memory[10] = {{10, false}, {20, false}, {30, false}, {15, false}, {25, false},
                               {35, false}, {40, false}, {10, false}, {20, false}, {30, false}};

    // Allocate memory using Best Fit algorithm
    best_fit(memory, 10, 20); // Allocate memory for a process of size 20
    best_fit(memory, 10, 30); // Allocate memory for a process of size 30

    return 0;
}
