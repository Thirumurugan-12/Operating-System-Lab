#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
main()
{
    int shmid;
    key_t key = 0x10;
    shmid = shmget(key, 100, IPC_CREAT | 0666);
    if (shmid < 0)
        printf("\nFirst SHMID failed\n");
    else
        printf("\nFirst SHMID Succeded id=%d \n", shmid);
    shmid = shmget(key, 101, IPC_CREAT | 0666);
    if (shmid < 0)
        printf("\nSecond SHMID failed\n");
    else
        printf("\nSecond SHMID Succeded id=%d \n", shmid);
    shmid = shmget(key, 90, IPC_CREAT | 0666);
    if (shmid < 0)
        printf("\nThird SHMID failed\n");
    else
        printf("\n Third SHMID Succeded id=%d \n", shmid);
}