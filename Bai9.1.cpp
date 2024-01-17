#include"stdio.h"

// Ham tinh thoi gian cho moi quy trinh  
void findWaitingTime(int processes[], int n, int bt[],int wt[])
{
	// Start = 0 
	wt[0] = 0;
	for(int i=1; i<n; i++)
		wt[i] = bt[i-1] + wt[i-1]; // TG = (TG cho  + TG xu ly) cua tien trinh truoc do  
}

// Ham tinh thoi gian quay vong cho moi quy trinh
void findTurnAroundTime(int processes[], int n, int bt[], int wt[],int tat[])
{
	for(int i=0; i<n; i++)
		tat[i] = bt[i] + wt[i]; // TG = TG cho + TG xu ly
}

// Ham tinh thoi gian cho trung binh va thoi gian quay vong trung binh
void findavgTime(int processes[], int n, int bt[])
{
	// mang luu thoi gian cho va thoi gian quay vong  
	int wt[n], tat[n];
	float total_wt = 0, total_tat = 0;
	
	// tinh thoi gian cho va thoi gian quay  
	findWaitingTime(processes, n, bt, wt);
	findTurnAroundTime(processes, n, bt, wt, tat);

	printf("Processes  Burst time  Waiting time  Turn around time\n");

	for(int i=0; i<n; i++)
	{
	 	total_wt = total_wt + wt[i];
	 	total_tat = total_tat + tat[i];
	 	printf("  %d",(i+1));
	 	printf("       %d",bt[i]);
	 	printf("             %d",wt[i]);
	 	printf("                 %d\n",tat[i]);
	 	
	}
	int s = (float)total_wt / (float)n;
	int t = (float)total_tat / (float)n;
	printf("\nAverage waiting time = %d\n",s);
	printf("\n"); 
	printf("Average turn around time = %d\n",t);
}

int main(){
	int processes[] = { 1, 2, 3}; // id quy trinh  
	int n = sizeof processes / sizeof processes[0]; // n = 3 
	int burst_time[] = {10, 5, 8}; // thoi gian xu ly  
	findavgTime(processes, n, burst_time);
	return 0;
}

