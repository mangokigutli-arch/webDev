#include <iostream>
using namespace std;

// First Fit
void firstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    cout << "\nFirst Fit Allocation:\n";
    for (int i = 0; i < n; i++)
    {
        if (allocation[i] != -1)
            cout << "Process " << i + 1 << " -> Block " << allocation[i] + 1 << endl;
        else
            cout << "Process " << i + 1 << " -> Not Allocated\n";
    }
}

// Best Fit
void bestFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int bestIndex = -1;

        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIndex == -1 || blockSize[j] < blockSize[bestIndex])
                    bestIndex = j;
            }
        }

        if (bestIndex != -1)
        {
            allocation[i] = bestIndex;
            blockSize[bestIndex] -= processSize[i];
        }
    }

    cout << "\nBest Fit Allocation:\n";
    for (int i = 0; i < n; i++)
    {
        if (allocation[i] != -1)
            cout << "Process " << i + 1 << " -> Block " << allocation[i] + 1 << endl;
        else
            cout << "Process " << i + 1 << " -> Not Allocated\n";
    }
}

// Worst Fit
void worstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int worstIndex = -1;

        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (worstIndex == -1 || blockSize[j] > blockSize[worstIndex])
                    worstIndex = j;
            }
        }

        if (worstIndex != -1)
        {
            allocation[i] = worstIndex;
            blockSize[worstIndex] -= processSize[i];
        }
    }

    cout << "\nWorst Fit Allocation:\n";
    for (int i = 0; i < n; i++)
    {
        if (allocation[i] != -1)
            cout << "Process " << i + 1 << " -> Block " << allocation[i] + 1 << endl;
        else
            cout << "Process " << i + 1 << " -> Not Allocated\n";
    }
}

// Next Fit
void nextFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
    int lastIndex = 0;

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        while (count < m)
        {
            if (blockSize[lastIndex] >= processSize[i])
            {
                allocation[i] = lastIndex;
                blockSize[lastIndex] -= processSize[i];
                break;
            }

            lastIndex = (lastIndex + 1) % m;
            count++;
        }
    }

    cout << "\nNext Fit Allocation:\n";
    for (int i = 0; i < n; i++)
    {
        if (allocation[i] != -1)
            cout << "Process " << i + 1 << " -> Block " << allocation[i] + 1 << endl;
        else
            cout << "Process " << i + 1 << " -> Not Allocated\n";
    }
}

int main()
{
    int block1[] = {100, 500, 200, 300, 600};
    int block2[] = {100, 500, 200, 300, 600};
    int block3[] = {100, 500, 200, 300, 600};
    int block4[] = {100, 500, 200, 300, 600};

    int processSize[] = {212, 417, 112, 426};

    int m = 5;
    int n = 4;

    firstFit(block1, m, processSize, n);
    bestFit(block2, m, processSize, n);
    worstFit(block3, m, processSize, n);
    nextFit(block4, m, processSize, n);

    return 0;
}
