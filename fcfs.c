#include <stdio.h>

int main() {
    int n, i, waiting_time = 0, turnaround_time = 0;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n];

    // Input burst time for each process
    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Burst time for process P%d: ", i);
        scanf("%d", &burst_time[i]);
    }

    // Calculate waiting time and turnaround time
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        waiting_time += burst_time[i];
        turnaround_time += waiting_time;
        printf("P%d\t%d\t\t%d\t\t%d\n", i, burst_time[i], waiting_time - burst_time[i], turnaround_time);
    }

    // Calculate average waiting time and average turnaround time
    float avg_waiting_time = (float)(waiting_time - burst_time[0]) / n;
    float avg_turnaround_time = (float)turnaround_time / n;
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
