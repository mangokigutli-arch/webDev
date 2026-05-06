/*Use the map of the area around the college as the graph.
Identify the prominent land marks as nodes.
Represent a given graph using adjacency matrix/list 
to perform DFS 
and 
using adjacency list to perform BFS.

INPUT: Graph G

OUTPUT:DFS / BFS travesals

AUTHOR: Sunil Rathod

DATE:17.02.2026

*/
#include<iostream>
using namespace std;

#define MAX 10

class Graph {
    int adj[MAX][MAX];   // adjacency matrix
    int visited[MAX];
    int n;

public:
    void createGraph() {
        cout << "Enter number of nodes: ";
        cin >> n;

        // initialize matrix
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                adj[i][j] = 0;

        int e, u, v;
        cout << "Enter number of edges: ";
        cin >> e;

        for(int i=0;i<e;i++) {
            cout << "Enter edge (u v): ";
            cin >> u >> v;
            adj[u][v] = 1;
        }
    }

    void display() {
        cout << "\nAdjacency Matrix:\n";
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++)
                cout << adj[i][j] << " ";
            cout << endl;
        }
    }

    void initVisited() {
        for(int i=1;i<=n;i++)
            visited[i] = 0;
    }

    // DFS (Recursive)
    void DFS(int v) {
        cout << v << " ";
        visited[v] = 1;

        for(int i=1;i<=n;i++) {
            if(adj[v][i] == 1 && visited[i] == 0)
                DFS(i);
        }
    }

    // BFS (Using Queue)
    void BFS(int start) {
        int queue[MAX], front=0, rear=0;

        queue[rear++] = start;
        visited[start] = 1;

        while(front < rear) {
            int v = queue[front++];
            cout << v << " ";

            for(int i=1;i<=n;i++) {
                if(adj[v][i] == 1 && visited[i] == 0) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
        }
    }
};

int main() {
    Graph g;
    int ch, start;

    do {
        cout << "\n1.Create Graph\n2.Display\n3.DFS\n4.BFS\n5.Exit\nChoice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                g.createGraph();
                break;

            case 2:
                g.display();
                break;

            case 3:
                cout << "Enter start node: ";
                cin >> start;
                g.initVisited();
                g.DFS(start);
                break;

            case 4:
                cout << "Enter start node: ";
                cin >> start;
                g.initVisited();
                g.BFS(start);
                break;

        }
    } while(ch != 5);

    return 0;
}