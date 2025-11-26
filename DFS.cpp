#include <iostream>
using namespace std;

#define MAX 100

int visited[MAX] = {0};
int adj[MAX][MAX] = {0};

void DFS(int node, int V) {
    visited[node] = 1;
    cout << node << " ";
    
    for (int i = 0; i < V; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            DFS(i, V);
        }
    }
}

int main() {
    int V = 5, E = 4;
    int edges[][2] = {{0,1}, {0,2}, {1,3}, {2,4}};
    
    for (int i = 0; i < E; i++) {
        int u = edges[i][0], v = edges[i][1];
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    cout << "DFS Traversal: ";
    DFS(0, V);
    cout << endl;
    return 0;
}
