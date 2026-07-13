#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define MAX 100

int dist[MAX];
int matrix[MAX][MAX];
int n;
int labels[MAX];
int parent[MAX];

typedef struct Edge {
    int u;
    int v;
    int weight;
} Edge;

Edge edges[MAX * MAX];
int edgeCount = 0;
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%c ", labels[j]);
        return;
    }
    printPath(parent, parent[j]);
    printf(" -> %c ", labels[j]);
}

void BellmanFord(int matrix[MAX][MAX], int src, int n) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < edgeCount; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }

    for (int j = 0; j < edgeCount; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = matrix[i][j];
                edgeCount++;
            }
        }
    }
    printf("Enter the labels of the vertices:\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &labels[i]);
    }
    int src;
    printf("Enter the source vertex index (0 to %d): ", n - 1);
    scanf("%d", &src);
    BellmanFord(matrix, src, n);
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%c \t\t %d \t\t Path: ", labels[i], dist[i]);
        printPath(parent, i);
        printf("\n");
    }
    return 0;
}
