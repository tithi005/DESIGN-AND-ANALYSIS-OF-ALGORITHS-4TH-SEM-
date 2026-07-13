#include <stdio.h>
#include <limits.h>
#define MAX 100
#define INF 999999

int matrix[MAX][MAX];
int dist[MAX][MAX];
char labels[MAX];
int n;

void floydWarshall(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                dist[i][j] = 0;
            } else if(matrix[i][j] != 0){
                dist[i][j] = matrix[i][j];
            } else {
                dist[i][j] = INF;
            }
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k] != INF && dist[k][j] != INF &&
                   dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(dist[i][i] < 0){
            printf("Graph contains a negative weight cycle.\n");
            return;
        }
    }

    printf("Shortest distance matrix:\n\t");
    for(int j = 0; j < n; j++){
        printf("%c\t", labels[j]);
    }
    printf("\n");

    for(int i = 0; i < n; i++){
        printf("%c\t", labels[i]);
        for(int j = 0; j < n; j++){
            if(dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

int main(){
    FILE *fp = fopen("graph.txt", "r");
    if(fp == NULL){
        printf("Error: could not open graph.txt\n");
        return 1;
    }

    fscanf(fp, "%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fscanf(fp, "%d", &matrix[i][j]);
        }
    }
    fclose(fp);

    for(int i = 0; i < n; i++){
        labels[i] = 'A' + i;
    }

    floydWarshall();

    return 0;
}