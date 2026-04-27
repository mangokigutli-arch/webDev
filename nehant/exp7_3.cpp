#include <iostream>
using namespace std;

// Function to find the page to replace
int findOptimal(int pages[], int frames[], int n, int index, int f) {
    int farthest = index;
    int pos = -1;

    for (int i = 0; i < f; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }

        // If page is never used again
        if (j == n)
            return i;
    }

    // If all pages are used again, return the farthest one
    return (pos == -1) ? 0 : pos;
}

// Optimal Page Replacement Function
void optimalPage(int pages[], int n, int f) {
    int frames[50];
    int pageFaults = 0;

    // Initialize frames as empty
    for (int i = 0; i < f; i++)
        frames[i] = -1;

    for (int i = 0; i < n; i++) {
        bool found = false;

        // Check if page already exists
        for (int j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = true;
                break;
            }
        }

        // If not found → page fault
        if (!found) {
            int pos = findOptimal(pages, frames, n, i + 1, f);
            frames[pos] = pages[i];
            pageFaults++;
        }

        // Print current frame status
        cout << "Step " << i + 1 << ": ";
        for (int j = 0; j < f; j++) {
            if (frames[j] != -1)
                cout << frames[j] << " ";
            else
                cout << "- ";
        }
        cout << endl;
    }

    cout << "\nTotal Page Faults = " << pageFaults << endl;
}

// Main Function
int main() {
    int n, f;

    cout << "Enter number of pages: ";
    cin >> n;

    int pages[50];
    cout << "Enter page reference string:\n";
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> f;

    optimalPage(pages, n, f);

    return 0;
}
