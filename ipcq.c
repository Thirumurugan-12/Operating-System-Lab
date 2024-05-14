#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MSG_SIZE 256

struct msg_buffer {
    long msg_type;
    char msg_text[MAX_MSG_SIZE];
};

int main() {
    key_t key;
    int msg_id;
    struct msg_buffer msg;

    // Generate a unique key
    key = ftok(".", 'M');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Create a message queue
    msg_id = msgget(key, 0666 | IPC_CREAT);
    if (msg_id == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Sender process
    if (fork() == 0) {
        // Prepare the message
        msg.msg_type = 1;
        strcpy(msg.msg_text, "Hello from the sender!");

        // Send the message
        if (msgsnd(msg_id, &msg, sizeof(msg.msg_text), 0) == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }

        printf("Message sent: %s\n", msg.msg_text);
    } else {  // Receiver process
        // Receive the message
        if (msgrcv(msg_id, &msg, sizeof(msg.msg_text), 1, 0) == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }

        printf("Message received: %s\n", msg.msg_text);

        // Delete the message queue
        if (msgctl(msg_id, IPC_RMID, NULL) == -1) {
            perror("msgctl");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
