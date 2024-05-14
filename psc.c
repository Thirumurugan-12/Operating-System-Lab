#include <stdio.h>

// Structure to represent a process
typedef struct {
    int process_id;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
} Process;

// Function to sort processes based on priority
void sort_processes(Process processes[], int n) {
    int i, j;
    Process temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                // Swap processes
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    // Input burst time and priority for each process
    printf("Enter burst time and priority for each process:\n");
    for (i = 0; i < n; i++) {
        printf("For process P%d:\n", i);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        processes[i].process_id = i;  // Assigning process IDs
    }

    // Sort processes based on priority
    sort_processes(processes, n);

    // Calculate waiting time and turnaround time
    int total_waiting_time = 0, total_turnaround_time = 0;
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;
    total_turnaround_time += processes[0].turnaround_time;
    for (i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].turnaround_time;
        total_waiting_time += processes[i].waiting_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    // Display process ID, burst time, priority, waiting time, and turnaround time
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].burst_time, processes[i].priority, processes[i].waiting_time, processes[i].turnaround_time);
    }

    // Calculate average waiting time and average turnaround time
    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
