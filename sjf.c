#include<stdio.h>

int main() {
	int n,j,temp,twt=0,ttat=0;

	printf("Enter the number of processes: ");
	scanf("%d",&n);

	int bt[n],wt[n],tat[n];


	printf("Enter burst time for each processes :\n");
	for (int i=0;i<n;i++) {
		printf("Burst Time for processes P%d: ",i);
		scanf("%d",&bt[i]);
	}

	for(int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			if (bt[i] > bt[j]) {
				temp = bt[i];
				bt[i] = bt[j];
				bt[j] = temp;
			}
		}
	}

	wt[0] = 0;
	tat[0] = bt[0];

	for(int i=1;i<n;i++) {
		wt[i] = wt[i-1] + bt[i-1];
		twt += wt[i];
		tat[i] = wt[i] + bt[i];
		ttat += tat[i];
	}

	printf("\nProcess\tBurst Time\tWaiting Time\tTurn around Time\n");
	for(int i=0;i<n;i++) {
		printf("P%d\t%d\t%d\t%d\n",i,bt[i],wt[i],tat[i]);
	}



}
