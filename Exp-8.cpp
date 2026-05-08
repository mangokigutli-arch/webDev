#include <iostream>
#include <cmath>
using namespace std;

// -------- SORT FUNCTION --------
void sortArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// -------- FCFS --------
void FCFS(int arr[], int n, int head)
{
    int seek = 0;

    cout << "\nFCFS Flow: " << head;

    for(int i = 0; i < n; i++)
    {
        seek += abs(arr[i] - head);
        head = arr[i];
        cout << " -> " << head;
    }

    cout << "\nTotal Seek = " << seek << endl;
}

// -------- SSTF --------
void SSTF(int arr[], int n, int head)
{
    int seek = 0;
    bool visited[10] = {false};

    cout << "\nSSTF Flow: " << head;

    for(int i = 0; i < n; i++)
    {
        int minDist = 9999, index = -1;

        for(int j = 0; j < n; j++)
        {
            if(!visited[j] && abs(arr[j] - head) < minDist)
            {
                minDist = abs(arr[j] - head);
                index = j;
            }
        }

        seek += minDist;
        head = arr[index];
        visited[index] = true;

        cout << " -> " << head;
    }

    cout << "\nTotal Seek = " << seek << endl;
}

// -------- SCAN --------
void SCAN(int arr[], int n, int head)
{
    int seek = 0;
    sortArray(arr, n);

    cout << "\nSCAN Flow: " << head;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] >= head)
        {
            seek += abs(arr[i] - head);
            head = arr[i];
            cout << " -> " << head;
        }
    }

    for(int i = n - 1; i >= 0; i--)
    {
        if(arr[i] < head)
        {
            seek += abs(arr[i] - head);
            head = arr[i];
            cout << " -> " << head;
        }
    }

    cout << "\nTotal Seek = " << seek << endl;
}

// -------- C-SCAN --------
void CSCAN(int arr[], int n, int head, int diskSize)
{
    int seek = 0;
    sortArray(arr, n);

    cout << "\nC-SCAN Flow: " << head;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] >= head)
        {
            seek += abs(arr[i] - head);
            head = arr[i];
            cout << " -> " << head;
        }
    }

    seek += abs(diskSize - head - 1);
    cout << " -> END";

    head = 0;
    cout << " -> 0";

    for(int i = 0; i < n; i++)
    {
        if(arr[i] < head)
        {
            seek += abs(arr[i] - head);
            head = arr[i];
            cout << " -> " << head;
        }
    }

    cout << "\nTotal Seek = " << seek << endl;
}

// -------- LOOK --------
void LOOK(int arr[], int n, int head)
{
    int seek = 0;
    sortArray(arr, n);

    cout << "\nLOOK Flow: " << head;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] >= head)
        {
            seek += abs(arr[i] - head);
            head = arr[i];
            cout << " -> " << head;
        }
    }

    for(int i = n - 1; i >= 0; i--)
    {
        if(arr[i] < head)
        {
            seek += abs(arr[i] - head);
            head = arr[i];
            cout << " -> " << head;
        }
    }

    cout << "\nTotal Seek = " << seek << endl;
}

// -------- C-LOOK --------
void CLOOK(int arr[], int n, int head)
{
    int seek = 0;
    sortArray(arr, n);

    cout << "\nC-LOOK Flow: " << head;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] >= head)
        {
            seek += abs(arr[i] - head);
            head = arr[i];
            cout << " -> " << head;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(arr[i] < head)
        {
            seek += abs(arr[i] - head);
            head = arr[i];
            cout << " -> " << head;
        }
    }

    cout << "\nTotal Seek = " << seek << endl;
}

// -------- MAIN --------
int main()
{
    int arr[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int n = 8;
    int head = 53;

    FCFS(arr, n, head);
    SSTF(arr, n, head);
    SCAN(arr, n, head);
    CSCAN(arr, n, head, 200);
    LOOK(arr, n, head);
    CLOOK(arr, n, head);

    return 0;
}
