#include<bits/stdc++.h>
using namespace std;
struct Process {
	int pid; // Process ID
	int bt; // Burst Time
	int art; // Arrival Time
};

// Ham tinh thoi gian cho  
void findWaitingTime(Process proc[], int n, int wt[]){
	int rt[n]; // luu thoi gian con lai cua moi tien trinh  
	// Copy the burst time into rt[]
	// Tim tien trinh va thoi gian con lai nho nhat trong cac tien trinh den tai thoi diem  
	for(int i=0; i<n; i++)
		rt[i] = proc[i].bt; // copy TG xu ly tu proc -> rt  
	int complete = 0; // theo gioi tien trinh hoan thanh  
	t = 0; // theo gioi thi gian hien tai  
	minm = INT_MAX; // luu thoi gian con lai nho nhat  
	int shortest = 0; // luu chi so tien trinh con lai nho nhat  
	finish_time; // luu thoi gian hoan thanh tien trinh  
	bool check = false;
	// Process until all processes gets
	// completed
	while(complete != n){
		// Find prcess with minimum
		// remaining time among the
		// processes that arrives till the
		// curent time
		
		// tim tien trinh co thoi gian con lai nho nhat ma  TG den <= TG hien tai  
		for(int j=0; j<n; j++){
			if((proc[j].art <= t) && (rt[j]<minm) && rt[j]>0) {
				minm = rt[j];
				shortest = j;
				check = true;
			}
		}
		// neu ko co tien trinh den trong TG hien tai  
		if(check == false){
			t++;
			continue;
		}
		// Reduce remaining time by one
		// giam TG con lai cua tien trinh nho nhat  
		rt[shortest]--;
		// Update minimun
		minm = rt[shortest];
		if(minm == 0)
			minm = INT_MAX;
		// If a process gets completely
		// excuted
		// neu tien trinh co TG  con lai nho nhat  hoan thanh  
		if(rt[shortest]==0){
			// Increment complete
			complete++;
			check = false;
			// Find finish time of current
			// process
			finish_time = t + 1;
			// calcute waiting time = TG hoan thanh - TG xu ly - Thoi diem tien trinh den  
			wt[shortest] = finish_time - proc[shortest].bt - proc[shortest].art;
			// neu TG cho duoc tinh < 0  
			if(wt[shortest] < 0)
				wt[shortest] = 0;
		}
		// Increment time
		t++;
	}
}

// Ham tinh thoi gian quay vong cho moi tien trinh   
void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]){
	// Calculating turnaround time by adding
	// bt[i] + wt[i]
	// Tim thoi gian con lai nho nhat 
	for(int i=0; i<n; i++)
		tat[i] = proc[i].bt + wt[i]; // TG = TG cho + TG xu ly  
}

// Ham tinh thoi gian cho tb va thoi gian quay tb  
void findavgTime(Process proc[],int n){
	int wt[n], tat[n], total_wt = 0, total_tat = 0;
	// Function to find waiting time of all
	// processes
	findWaitingTime(proc,n,wt);
	// Function to find turn around time for
	// all processes
	findTurnAroundTime(proc,n,wt,tat);
	// Display processes along with all
	// details
	cout << "Processes "
		<< " Burst time "
		<< " Waiting time "
		<< " Turn around time\n";
	// Calculate total waiting time and
	// total turnaround time
	for(int i=0; i<n; i++){
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << proc[i].pid << "\t\t"
			<< proc[i].bt << "\t\t" << wt[i] 
			<< "\t\t " << tat[i] << endl;
	}
	cout << "\nAverage waiting time = "
		<< (float)total_wt / (float)n;
	cout << "\nAvergare turn around time = "
	    << (float)total_tat / (float)n;
}

// Driver code
int main(){
	Process proc[] = { {1, 6, 1}, { 2, 8, 1}, { 3, 7, 2}, { 4, 3, 3}};
	int n = sizeof(proc) / sizeof(proc[0]);
	findavgTime(proc,n);
	return 0;
}
