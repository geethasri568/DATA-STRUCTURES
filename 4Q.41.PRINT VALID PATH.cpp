#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Function to print a valid path from source to destination
void printPath(int parent[], int vertex) {
    if (parent[vertex] == -1) {
        printf("%d ", vertex);
        return;
    }
    printPath(parent, parent[vertex]);
    printf("%d ", vertex);
}

// Function to find a path using Depth First Search
bool findPathDFS(int graph[][MAX_VERTICES], int vertices, int source, int destination, bool visited[], int parent[]) {
    visited[source] = true;

    if (source == destination) {
        printPath(parent, destination);
        return true;
    }

    for (int i = 0; i < vertices; i++) {
        if (graph[source][i] && !visited[i]) {
            parent[i] = source;
            if (findPathDFS(graph, vertices, i, destination, visited, parent))
                return true;
        }
    }

    return false;
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

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges:\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // Assuming a directed graph
    }

    int source, destination;
    printf("Enter the source and destination vertices: ");
    scanf("%d %d", &source, &destination);

    bool visited[MAX_VERTICES] = {false};
    int parent[MAX_VERTICES];
    for (int i = 0; i < vertices; i++) {
        parent[i] = -1;
    }

    if (!findPathDFS(graph, vertices, source, destination, visited, parent))
	 {
        printf("No valid path exists between the source and destination.\n");
}
}
