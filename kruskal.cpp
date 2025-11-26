#include <iostream>
using namespace std;

#define MAX 100

struct Edge {
    int src, dest, weight;
};

struct subset {
    int parent, rank;
};

int find(subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void bubbleSort(Edge edges[], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void KruskalMST(Edge edges[], int V, int E) {
    Edge result[MAX];
    int e = 0, i = 0;
    
    bubbleSort(edges, E);
    
    subset* subsets = new subset[V];
    
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    
    while (e < V - 1 && i < E) {
        Edge next_edge = edges[i++];
        
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    
    cout << "Edges in MST:" << endl;
    int minCost = 0;
    for (i = 0; i < e; i++) {
        cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
        minCost += result[i].weight;
    }
    cout << "Minimum Cost: " << minCost << endl;
    delete[] subsets;
}

int main() {
    int V = 4, E = 5;
    Edge edges[] = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };
    
    KruskalMST(edges, V, E);
    return 0;
}
