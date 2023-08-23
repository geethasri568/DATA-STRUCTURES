#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Function to find the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to convert a given graph into an adjacency matrix
void convertToAdjMatrix(int graph[][MAX_VERTICES], int vertices, int edges) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges:\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1; // Assuming an undirected graph
    }
}

// Function to find the minimum number of edges to traverse the graph
int findMinimumEdges(int graph[][MAX_VERTICES], int vertices) {
    int sum = 0;

    for (int i = 0; i < vertices; i++) {
        int edgeCount = 0;
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j] == 1) {
                edgeCount++;
            }
        }
        if (edgeCount > 0) {
            sum += min(vertices - edgeCount, edgeCount);
        }
    }

    return sum / 2; // Divide by 2 since each edge is counted twice in an undirected graph
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int vertices, edges;

    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    if (vertices > MAX_VERTICES) {
        printf("Too many vertices. Maximum allowed is %d.\n", MAX_VERTICES);
        return 1;
    }

    convertToAdjMatrix(graph, vertices, edges);

    int minEdges = findMinimumEdges(graph, vertices);
    printf("The minimum number of edges required to traverse the graph is: %d\n", minEdges);

}
