#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

struct Cell {
    int x, y, dist;
};

int minDistance(int dist[], bool visited[], int size) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < size; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int gridDijkstra(int grid[MAX][MAX], int m, int n) {
    int size = m * n;
    int dist[MAX];
    bool visited[MAX] = {false};
    
    for (int i = 0; i < size; i++) {
        dist[i] = INT_MAX;
    }
    dist[0] = grid[0][0];
    
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    for (int count = 0; count < size - 1; count++) {
        int u = minDistance(dist, visited, size);
        visited[u] = true;
        
        int x = u / n;
        int y = u % n;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                int v = nx * n + ny;
                if (!visited[v] && dist[u] != INT_MAX && 
                    dist[u] + grid[nx][ny] < dist[v]) {
                    dist[v] = dist[u] + grid[nx][ny];
                }
            }
        }
    }
    
    return dist[size - 1];
}

int main() {
    int grid[MAX][MAX] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m = 3, n = 3;
    
    cout << "Minimum cost: " << gridDijkstra(grid, m, n) << endl;
    return 0;
}
