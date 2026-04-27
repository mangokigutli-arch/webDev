#include <iostream>     
#include <climits>      
using namespace std;    
int main()
{
    int n;              
    cout << "Enter number of processes: ";
    cin >> n;           
    int at[n], bt[n], rt[n]; 
    int ct[n], tat[n], wt[n]; 
    for(int i = 0; i < n; i++)
    {
        cout << "Enter Arrival Time and Burst Time for P" << i+1 << ": ";
        cin >> at[i] >> bt[i]; 
        rt[i] = bt[i];       
    }
    int time = 0;        
    int completed = 0;   
    while(completed < n) 
    {
        int minRT = INT_MAX; 
        int index = -1;     
        for(int i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                if(rt[i] < minRT)
                {
                    minRT = rt[i]; 
                    index = i;    
                }
            }
        }
        if(index != -1)
        {
            rt[index]--; 
            time++;      
            if(rt[index] == 0)
            {
                completed++;       
                ct[index] = time;  
                tat[index] = ct[index] - at[index];
                wt[index] = tat[index] - bt[index]; 
            }
        }
        else
        {
            time++; 
        }
    }
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++)
    {
        cout << i+1 << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\n";
    }

    return 0;
}