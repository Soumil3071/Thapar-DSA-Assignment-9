#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;
int visited[MAX] = {0};
int adj[MAX][MAX] = {0};

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void BFS(int start, int V) {
    enqueue(start);
    visited[start] = 1;
    
    printf("BFS Traversal: ");
    
    while (front <= rear) {
        int current = dequeue();
        printf("%d ", current);
        
        for (int i = 0; i < V; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int V = 5, E = 4;
    int edges[][2] = {{0,1}, {0,2}, {1,3}, {2,4}};
    
    for (int i = 0; i < E; i++) {
        int u = edges[i][0], v = edges[i][1];
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    BFS(0, V);
    return 0;
}
