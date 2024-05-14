#include <stdio.h>
void main()
{
    int a[25], p[25], j, t, n, i, wt = 0, swt = 0, tt = 0, stt = 0;
    printf("\nSHORTEST JOB NEXT SCHEDULING PROCESS\n");
    printf("Enter the no. of jobs: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nService Time or Burst Time for a process %d: ", i);
        scanf("%d", &a[i]);
        p[i] = i;
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
                t = p[i];
            }
        }
    }
    printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurn Around Time");
    for (i = 0; i < n; i++)
    {
        swt = swt + wt;
        tt = tt + a[i];
        stt = stt + tt;
        printf("\nP%d\t\t%d\t\t\t%d\t\t\t%d", i, a[i], wt, tt);
        wt = wt + a[i];
    }
    printf("\n\n\tAverage Waiting Time=%d", swt / n);
    printf("\n\n\tAverage Turn Around Time=%d", stt / n);
}