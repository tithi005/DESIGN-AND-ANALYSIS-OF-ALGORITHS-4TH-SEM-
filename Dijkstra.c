#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define MAX 100
int matrix[MAX][MAX];
int n;
int dist[MAX];
int labels[MAX];
int sptSet[MAX];
int parent[MAX];

int ExtractMin(int dist[], int sptSet[], int n){
    int min = INT_MAX;
    int minIndex = -1;
    for(int i = 0; i < n; i++){
        if(sptSet[i] == 0 && dist[i] <= min){
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void PrintPath(int parent[], int j){
    if(parent[j] == -1){
        printf("%c ", labels[j]);
        return;
    }
    PrintPath(parent, parent[j]);
    printf(" -> %c ", labels[j]);
}

void Dijkstra(int matrix[MAX][MAX], int src, int n){
    for(int i = 0; i < n; i++){
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        parent[i] = -1;
    }
    dist[src] = 0;
    for(int count = 0; count < n - 1; count++){
        int u = ExtractMin(dist, sptSet, n);
        sptSet[u] = 1;
        for(int v = 0; v < n; v++){
            if(!sptSet[v] && matrix[u][v] && dist[u] != INT_MAX && dist[u] + matrix[u][v] < dist[v]){
                dist[v] = dist[u] + matrix[u][v];
                parent[v] = u;
            }
        }
    }
}

int main(){
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Enter the labels of the vertices:\n");
    for(int i = 0; i < n; i++){
        scanf(" %c", &labels[i]);
    }
    int src;
    printf("Enter the source vertex index (0 to %d): ", n-1);
    scanf("%d", &src);
    Dijkstra(matrix, src, n);
    printf("Vertex\tDistance from Source\tPath\n");
    for(int i = 0; i < n; i++){
        printf("%c\t%d\t\t\t", labels[i], dist[i]);
        PrintPath(parent, i);
        printf("\n");
    }
    return 0;
}
