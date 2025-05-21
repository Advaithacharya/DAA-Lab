#include <stdio.h>
#define MAX 20
#define INF 999

int dist[MAX];
int visited[MAX];
int path[MAX];
int source;

int minDistance(int n) {
    int min = INF, minIndex = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void printPath(int path[], int j) {
    if (path[j] == -1) return;
    printPath(path, path[j]);
    printf(" --> %d", j);
}

void printShortest(int n) {
    for (int i = 1; i <= n; i++) {
        if (i != source) {
            printf("\nShortest distance from node %d to %d = %d\n", source, i, dist[i]);
            printf("Path: %d", source);
            printPath(path, i);
            printf("\n");
        }
    }
}

void dijkstra(int n, int graph[MAX][MAX]) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        path[i] = -1;
    }

    dist[source] = 0;

    for (int i = 1; i < n; i++) {
        int u = minDistance(n);
        if (u == -1) break; // No more reachable vertices
        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                path[v] = u;
            }
        }
    }
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter the number of nodes: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("Enter the weight matrix (use %d for INF/no path):\n", INF);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (scanf("%d", &graph[i][j]) != 1) {
                printf("Invalid input.\n");
                return 1;
            }
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;  // Set to INF if no edge exists
        }
    }

    printf("Enter the source vertex: ");
    if (scanf("%d", &source) != 1 || source < 1 || source > n) {
        printf("Invalid source vertex.\n");
        return 1;
    }

    dijkstra(n, graph);
    printShortest(n);

    return 0;
}
