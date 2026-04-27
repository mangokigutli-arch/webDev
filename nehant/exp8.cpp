#include <iostream>
#include <cmath>
using namespace std;
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
            }        }    }}
void FCFS(int arr[], int n, int head)
{
    int seek = 0;
    cout << "\nFCFS Flow: " << head;

    for(int i = 0; i < n; i++)
    {
        int distance = abs(arr[i] - head);
        seek += distance;
        head = arr[i];
        cout << " -> " << head;
    }

    cout << "\nTotal Seek: " << seek << endl;
}
void SSTF(int arr[], int n, int head)
{
    int seek = 0;
    bool visited[100] = {false};

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
    cout << "\nTotal Seek: " << seek << endl;
}
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
    cout << "\nTotal Seek: " << seek << endl;
}
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
            cout << " -> " << head;        }   }
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

    cout << "\nTotal Seek: " << seek << endl;
}

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
        }    }
    for(int i = n - 1; i >= 0; i--)
    {
        if(arr[i] < head)
        {
            seek += abs(arr[i] - head);
            head = arr[i];
            cout << " -> " << head;
        }    }
    cout << "\nTotal Seek: " << seek << endl;
}
void CLOOK(int arr[], int n, int head)
{
    int seek = 0;
    sortArray(arr, n);

    cout << "\nC-LOOK Flow: " << head;

    // move right
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
            cout << " -> " << head;       }    }
    cout << "\nTotal Seek: " << seek << endl;
}
int main()
{
    int n, head, diskSize;
    cout << "Enter number of requests: ";
    cin >> n;
    int arr[100];
    cout << "Enter requests: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter initial head position: ";
    cin >> head;
    cout << "Enter disk size: ";
    cin >> diskSize;
    FCFS(arr, n, head);
    SSTF(arr, n, head);
    SCAN(arr, n, head);
    CSCAN(arr, n, head, diskSize);
    LOOK(arr, n, head);
    CLOOK(arr, n, head);
    return 0;
}
