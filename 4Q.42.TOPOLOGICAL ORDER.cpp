#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Function to perform topological sorting
void topologicalSort(int graph[][MAX_VERTICES], int vertices, int indegree[], int sortedOrder[]) {
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    // Initialize queue with vertices having indegree 0
    for (int i = 0; i < vertices; i++) {
        if (indegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    int index = 0; // Index to keep track of the sorted order

    while (front != rear) {
        int currentVertex = queue[++front];
        sortedOrder[index++] = currentVertex;

        // Decrease the indegree of adjacent vertices and enqueue them if indegree becomes 0
        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i]) {
                if (--indegree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        }
    }
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

    int indegree[MAX_VERTICES] = {0}; // Stores the indegree of each vertex
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
        indegree[v]++;
    }

    int sortedOrder[MAX_VERTICES];
    topologicalSort(graph, vertices, indegree, sortedOrder);

    printf("Topological Order: ");
    for (int i = 0; i < vertices; i++) {
        printf("%d ", sortedOrder[i]);
    }
    printf("\n");
   return();
}
