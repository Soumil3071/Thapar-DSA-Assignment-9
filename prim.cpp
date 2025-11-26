#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;
    
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[MAX][MAX], int V) {
    cout << "Edges in MST:" << endl;
    int minCost = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " -- " << i << " == " << graph[i][parent[i]] << endl;
        minCost += graph[i][parent[i]];
    }
    cout << "Minimum Cost: " << minCost << endl;
}

void PrimMST(int graph[MAX][MAX], int V) {
    int parent[MAX], key[MAX];
    bool mstSet[MAX];
    
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    
    key[0] = 0;
    parent[0] = -1;
    
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;
        
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    printMST(parent, graph, V);
}

int main() {
    int V = 5;
    int graph[MAX][MAX] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    
    PrimMST(graph, V);
    return 0;
}
