#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {
    int shm_id;
    char *shm_ptr;
    key_t key;

    // Generate a unique key
    key = ftok(".", 'S');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Create shared memory segment
    shm_id = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach shared memory segment to process address space
    shm_ptr = (char *)shmat(shm_id, NULL, 0);
    if (shm_ptr == (char *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Parent process (writes to shared memory)
    if (fork() != 0) {
        printf("Parent Process (PID: %d)\n", getpid());

        // Write message to shared memory
        printf("Enter message to share with child process: ");
        fgets(shm_ptr, SHM_SIZE, stdin);
		

        // Wait for child process to read from shared memory
        sleep(5);

        // Detach and remove shared memory segment
        if (shmdt(shm_ptr) == -1) {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }
        if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(EXIT_FAILURE);
        }
    } 
    // Child process (reads from shared memory)
    else {
        printf("Child Process (PID: %d)\n", getpid());

        // Wait for parent process to write to shared memory
        sleep(1);

        // Read message from shared memory
        printf("Message received from parent: %s", shm_ptr);

        // Detach shared memory segment
        if (shmdt(shm_ptr) == -1) {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
