#include <iostream>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> m;

    int alloc[100][100], max[100][100], need[100][100];
    int avail[100];

    // Allocation Matrix
    cout << "\nEnter Allocation Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> alloc[i][j];
        }
    }

    // Max Matrix
    cout << "\nEnter Max Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> max[i][j];
        }
    }

    // Available Resources
    cout << "\nEnter Available Resources:\n";
    for (int j = 0; j < m; j++) {
        cin >> avail[j];
    }

    // Need Matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    bool finish[100] = {false};
    int safeSeq[100];
    int work[100];

    // Copy available to work
    for (int j = 0; j < m; j++) {
        work[j] = avail[j];
    }

    int count = 0;

    while (count < n) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool possible = true;

                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    for (int j = 0; j < m; j++) {
                        work[j] += alloc[i][j];
                    }

                    safeSeq[count] = i;
                    count++;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "\nSystem is NOT in safe state\n";
            return 0;
        }
    }

    cout << "\nSystem is in SAFE STATE\n";
    cout << "Safe Sequence: ";

    for (int i = 0; i < n; i++) {
        cout << "P" << safeSeq[i] << " ";
    }

    return 0;
}
