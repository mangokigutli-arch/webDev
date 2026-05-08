#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n], pr[n], rt[n], ct[n], tat[n], wt[n];

    // Input
    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival Time, Burst Time and Priority for P" << i + 1 << ": ";
        cin >> at[i] >> bt[i] >> pr[i];
        rt[i] = bt[i]; // remaining time
    }

    int time = 0, completed = 0;

    while (completed < n) {
        int index = -1;
        int highest_priority = 9999;

        // Find highest priority process (lower number = higher priority)
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                if (pr[i] < highest_priority) {
                    highest_priority = pr[i];
                    index = i;
                }
            }
        }

        if (index != -1) {
            rt[index]--;
            time++;

            // Process completed
            if (rt[index] == 0) {
                ct[index] = time;
                tat[index] = ct[index] - at[index];
                wt[index] = tat[index] - bt[index];
                completed++;
            }
        } else {
            time++; // CPU idle
        }
    }

    // Output (same format as your image)
    cout << "\nProcess AT BT PR CT TAT WT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << " "
             << at[i] << " "
             << bt[i] << " "
             << pr[i] << " "
             << ct[i] << " "
             << tat[i] << " "
             << wt[i] << endl;
    }

    return 0;
}
