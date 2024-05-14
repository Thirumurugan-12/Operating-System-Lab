#include <stdio.h>
#include <stdbool.h>

#define MEMORY_SIZE 100

// Structure to represent a memory block
typedef struct {
    int size;
    bool allocated;
} MemoryBlock;

// Function to allocate memory using First Fit algorithm
void first_fit(MemoryBlock memory[], int n, int process_size) {
    for (int i = 0; i < n; i++) {
        if (!memory[i].allocated && memory[i].size >= process_size) {
            memory[i].allocated = true;
            printf("Memory allocated for process of size %d\n", process_size);
            return;
        }
    }
    printf("Memory allocation failed for process of size %d\n", process_size);
}

int main() {
    MemoryBlock memory[10] = {{10, false}, {20, false}, {30, false}, {15, false}, {25, false},
                               {35, false}, {40, false}, {10, false}, {20, false}, {30, false}};

    // Allocate memory using First Fit algorithm
    first_fit(memory, 10, 20); // Allocate memory for a process of size 20
    first_fit(memory, 10, 30); // Allocate memory for a process of size 30

    return 0;
}
