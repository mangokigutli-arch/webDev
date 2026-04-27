#include <iostream>
using namespace std;

void LRU(int pages[], int n, int f) {
    int frames[10], time[10];
    int faults = 0, counter = 0;

    // initialize
    for(int i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        bool found = false;

        // check if page exists
        for(int j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                found = true;
                break;
            }
        }

        // page fault
        if(!found) {
            int pos = 0;

            // find LRU
            for(int j = 1; j < f; j++) {
                if(time[j] < time[pos]) {
                    pos = j;
                }
            }

            frames[pos] = pages[i];
            counter++;
            time[pos] = counter;
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
cout<<"lru algorithm"<<endl;
    LRU(pages, n, frames);

    return 0;
}
