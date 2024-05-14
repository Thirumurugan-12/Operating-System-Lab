#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
char name[50];
int main()
{
    int pid, len, qid;
    struct
    {
        long mtype;
        char mtext[50];
    } message;
    system("clear");
    printf("\n Inter Process communication using message queue \n");
    qid = msgget((key_t)13, IPC_CREAT | 0666);
    printf("\n\nMessage queue is created \n");
    if (qid == -1)
    {
        printf("\nMessage queue is not created \n");
        exit(1);
    }
    printf("\nThe value of qid is %d", qid);
    printf("\nEnter the message for communication: ");
    scanf("%s", name);
    strcpy(message.mtext, name);
    message.mtype = 1;
    len = strlen(message.mtext);
    pid = fork();
    printf("\n The value of pid is %d \n", pid);
    if (pid == 0)
    {
        msgsnd(qid, &message, len, IPC_NOWAIT);
        printf("\n\n MESSAGE SEND BY CHILD PROCESS\n");
    }
    if (pid > 0)
    {
        wait();
        msgrcv(qid, &message, strlen(message.mtext), 0, IPC_NOWAIT | MSG_NOERROR);
        printf("\n MESSAGE RECEIVED BY PARENT PROCESS\n");
        printf("\n Received message is %s \n", message.mtext);
    }
    if (pid == -1)
    {
        printf("\n Error in creating a child \n");
        exit(1);
    }
}