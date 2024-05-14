#include <stdio.h>
#include <stdbool.h>

#define PAGE_SIZE 1024
#define NUM_FRAMES 4
#define NUM_PAGES 8

// Function to simulate address translation (mapping virtual address to physical address)
int translate_address(int virtual_address, int page_table[]) {
    int page_number = virtual_address / PAGE_SIZE;

    if (page_number >= NUM_PAGES || page_table[page_number] == -1) {
        printf("Page fault occurred for virtual address %d\n", virtual_address);
        return -1; // Page fault
    }

    int frame_number = page_table[page_number];
    int offset = virtual_address % PAGE_SIZE;
    int physical_address = frame_number * PAGE_SIZE + offset;
    printf("Virtual address %d maps to physical address %d\n", virtual_address, physical_address);
    return physical_address;
}

int main() {
    int page_table[NUM_PAGES] = {0, 1, -1, 2, 3, -1, -1, -1};
    int virtual_addresses[] = {2048, 4096, 1024, 8192};

    // Simulate address translation for virtual addresses
    for (int i = 0; i < sizeof(virtual_addresses) / sizeof(virtual_addresses[0]); i++) {
        int virtual_address = virtual_addresses[i];
        int physical_address = translate_address(virtual_address, page_table);
        if (physical_address == -1) {
            page_table[virtual_address / PAGE_SIZE] = i % NUM_FRAMES;
            physical_address = translate_address(virtual_address, page_table);
        }
    }

    return 0;
}
