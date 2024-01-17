#include"iostream"
using namespace std;
// Function to find the waiting time for all
// processes

// Ham tinh thoi gian cho 
void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum)
{
	// Make a copy of burst times bt[] to store remaining
	// burst times.
	int rem_bt[n]; // khoi tao mang theo gioi TG con lai  
	for(int i=0; i<n; i++)
		rem_bt[i] = bt[i]; // sao chep thoi gian xu ly tu bt -> rem_bt
	int t = 0; // Current time
	// Kepp traversing processes in round robin manner
	// Until all of them are not done
	// duyet tien trinh
	while(1)
	{
		bool done = true; // hoan thanh 
		// Traverse all processes one by one repeatedly
		for(int i=0; i<n; i++){
			// If burst time of a process is greater than 0
			// then only need to process futher
			// neu TG con lai > 0  
			if(rem_bt[i] > 0)
			{
				done = false; //There is a pending process
				if(rem_bt[i]>quantum) // neu TG con lai > TG quantum
				{
					// Increase the value of t i.e. shows
					// how much time a process has been processed
					t += quantum; // tang TG con lai 1 luong
					// Decrese the burst_time of current process
					// by quantum
					rem_bt[i] -= quantum; // giam TG con lai 1 luong
				}
				
				// If burst time is smaller than or equal to
				// quantum, Last cycle for this process
				// neu TG con lai <= luong TG
				else
				{
					// Increase the value of t i.e. shows
					// how much time a process has been processed
					t = t + rem_bt[i]; // tang TG hien tai
					
					// Waiting time is current time minus time
					// used by this process
					wt[i] = t - bt[i];
					// As the process gets fully excuted
					// make its remaining burst time = 0
					rem_bt[i] = 0;
				}
			}
		}
		// If all processes are done
		if(done == true)
			break;
	}
}

// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n, int bt[], int wt[],int tat[]){
	// calculating turnaround time by adding
	// bt[i] + wt[i]
	for(int i=0; i<n; i++)
		tat[i] = bt[i] + wt[i]; // TG = TG cho + TG xu ly
}

// Function to calculate average time
void findavgTime(int processes[], int n, int bt[], int quantum){
	int wt[n],tat[n]; // luu TG cho va TG quay  
	total_wt = 0, total_tat = 0; // luu tong TG cho va TG quay  
	//Function to dind waiting time of all processes
	findWaitingTime(processes,n,bt,wt,quantum);
	// Function to find turn around time for all processes
	findTurnAroundTime(processes,n,bt,wt,tat);
	// Dispalay processes along with all details
	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n";
	// Calculate total waiting time and total turn
	// around time
	for(int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
			<< wt[i] <<"\t\t " << tat[i] << endl; 
	 }
	 cout << "Average waiting time = "
	 	<< (float)total_wt / (float)n;
	 cout << "\nAverage turn around time = "
	 	<< (float)total_tat / (float)n; 
}

// Driver code
int main(){
	// process id's
	int processes[] = { 1, 2, 3};
	int n = sizeof processes / sizeof processes[0];
	// Burst time of all processes
	int burst_time[] = {10, 5, 8};
	// Time quantum
	int quantum = 2;
	findavgTime(processes, n, burst_time, quantum);
	return 0;
}
