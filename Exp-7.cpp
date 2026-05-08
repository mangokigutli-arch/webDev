#include <iostream>
using namespace std;

// Function to check if page is present
bool isPresent(int frame[], int frames, int page)
{
    for(int i = 0; i < frames; i++)
    {
        if(frame[i] == page)
            return true;
    }
    return false;
}

// ---------------- FIFO ----------------
void FIFO(int pages[], int n, int frames)
{
    int frame[10];
    int index = 0;
    int faults = 0;

    for(int i = 0; i < frames; i++)
        frame[i] = -1;

    for(int i = 0; i < n; i++)
    {
        if(!isPresent(frame, frames, pages[i]))
        {
            frame[index] = pages[i];
            index = (index + 1) % frames;
            faults++;
        }
    }

    cout << "FIFO Page Faults = " << faults << endl;
}

// ---------------- LRU ----------------
void LRU(int pages[], int n, int frames)
{
    int frame[10], time[10];
    int faults = 0, counter = 0;

    for(int i = 0; i < frames; i++)
    {
        frame[i] = -1;
        time[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        int found = 0;

        for(int j = 0; j < frames; j++)
        {
            if(frame[j] == pages[i])
            {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        if(!found)
        {
            int min = 0;
            for(int j = 1; j < frames; j++)
            {
                if(time[j] < time[min])
                    min = j;
            }

            frame[min] = pages[i];
            counter++;
            time[min] = counter;
            faults++;
        }
    }

    cout << "LRU Page Faults = " << faults << endl;
}

// ---------------- OPTIMAL ----------------
void Optimal(int pages[], int n, int frames)
{
    int frame[10];
    int faults = 0;

    for(int i = 0; i < frames; i++)
        frame[i] = -1;

    for(int i = 0; i < n; i++)
    {
        if(!isPresent(frame, frames, pages[i]))
        {
            int index = -1, farthest = i;

            for(int j = 0; j < frames; j++)
            {
                int k;
                for(k = i + 1; k < n; k++)
                {
                    if(frame[j] == pages[k])
                        break;
                }

                if(k > farthest)
                {
                    farthest = k;
                    index = j;
                }
            }

            if(index == -1)
                index = 0;

            frame[index] = pages[i];
            faults++;
        }
    }

    cout << "Optimal Page Faults = " << faults << endl;
}

// ---------------- MAIN ----------------
int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4};
    int n = 8;
    int frames = 3;

    FIFO(pages, n, frames);
    LRU(pages, n, frames);
    Optimal(pages, n, frames);

    return 0;
}
