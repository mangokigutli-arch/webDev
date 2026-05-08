#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n];
    bool completed[n];

    // Input
    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival Time and Burst Time for P" << i + 1 << ": ";
        cin >> at[i] >> bt[i];
        rt[i] = bt[i];
        completed[i] = false;
    }

    int time = 0, completedCount = 0;

    while (completedCount < n) {
        int minRT = INT_MAX;
        int index = -1;

        // Find process with minimum remaining time
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                if (rt[i] < minRT) {
                    minRT = rt[i];
                    index = i;
                }
            }
        }

        if (index == -1) {
            time++;
        } else {
            rt[index]--;
            time++;

            if (rt[index] == 0) {
                completed[index] = true;
                completedCount++;

                ct[index] = time;
                tat[index] = ct[index] - at[index];
                wt[index] = tat[index] - bt[index];
            }
        }
    }

    // Output (Formatted like your image)
    cout << "\nProcess AT BT CT TAT WT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "      "
             << at[i] << "  "
             << bt[i] << "  "
             << ct[i] << "  "
             << tat[i] << "   "
             << wt[i] << endl;
    }

    return 0;
}
