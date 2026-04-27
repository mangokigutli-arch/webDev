#include <iostream>
using namespace std;

void FIFO(int pages[], int n, int f) {
    int frames[10];
    int faults = 0;
    int index = 0; // to track which frame to replace

    // initialize frames
    for(int i = 0; i < f; i++) {
        frames[i] = -1;
    }

    for(int i = 0; i < n; i++) {
        bool found = false;

        // check if page already in frames
        for(int j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = true;
                break;
            }
        }

        // if not found → page fault
        if(!found) {
            frames[index] = pages[i];
            index = (index + 1) % f; // move in circular way
            faults++;
        }

        // print frames
        cout << "Step " << i+1 << ": ";
        for(int j = 0; j < f; j++) {
            if(frames[j] != -1)
                cout << frames[j] << " ";
            else
                cout << "- ";
        }
        cout << endl;
    }

    cout << "\nTotal Page Faults = " << faults << endl;
}

int main() {
    int pages[] = {4, 7, 6, 1, 7, 6, 1, 2, 7, 2};
    int n = 10;
    int frames = 3;
    cout<< "fifo algorithm"<<endl;
    FIFO(pages, n, frames);

    return 0;
}
