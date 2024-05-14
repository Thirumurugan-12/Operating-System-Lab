#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MSG_SIZE 256

int main() {
    int pipe_fds[2];
    pid_t pid;
    char message[MSG_SIZE];

    // Create a pipe
    if (pipe(pipe_fds) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process (receiver)
        close(pipe_fds[1]); // Close write end of the pipe
        printf("Child Process (PID: %d)\n", getpid());

        // Read message from the pipe
        read(pipe_fds[0], message, sizeof(message));
        printf("Message received from parent: %s\n", message);

        close(pipe_fds[0]); // Close read end of the pipe
    } else { // Parent process (sender)
        close(pipe_fds[0]); // Close read end of the pipe
        printf("Parent Process (PID: %d)\n", getpid());

        // Write message to the pipe
        printf("Enter message to send to child: ");
        fgets(message, sizeof(message), stdin);
        write(pipe_fds[1], message, strlen(message) + 1);

        close(pipe_fds[1]); // Close write end of the pipe
    }

    return 0;
}
