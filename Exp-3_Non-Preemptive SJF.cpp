#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n], ct[n], tat[n], wt[n];
    bool completed[n];

    // Input
    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival Time and Burst Time for P" << i + 1 << ": ";
        cin >> at[i] >> bt[i];
        completed[i] = false;
    }

    int time = 0, done = 0;

    while (done < n) {
        int minBT = 9999;
        int index = -1;

        // Find process with minimum burst time
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && completed[i] == false) {
                if (bt[i] < minBT) {
                    minBT = bt[i];
                    index = i;
                }
            }
        }

        if (index != -1) {
            time += bt[index];
            ct[index] = time;
            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];
            completed[index] = true;
            done++;
        } else {
            time++; // CPU idle
        }
    }

    // Output (same format as your image)
    cout << "\nProcess AT BT CT TAT WT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << " "
             << at[i] << " "
             << bt[i] << " "
             << ct[i] << " "
             << tat[i] << " "
             << wt[i] << endl;
    }

    return 0;
}
