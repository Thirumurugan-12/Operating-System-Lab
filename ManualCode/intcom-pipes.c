#include <stdio.h>
main()
{
    int pid, ppid, pdes[2], n, a;
    printf("\nInterprocess communication using pipes");
    if (pipe(pdes) == -1)
    {
        printf("\n\tThere is no error");
        exit(1);
    }
    else
    {
        pid = fork();
        if (pid == -1)
            printf("\nThere is an error in the process");
        else if (pid)
        {
            close(pdes[0]);
            printf("\nParent is %d\n", ppid);
            printf("\nProcess is %d\n", pid);
            printf("\nEnterno.of process");
            scanf("%d", &a);
            write(pdes[1], &a, sizeof(a));
        }
        else
        {
            close(pdes[1]);
            open(pdes[0]);
            read(pdes[0], &n, sizeof(a));
            if (n % 2 == 0)
                printf("\nThe number %d is even", n);
        }
    }
}