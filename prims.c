#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#define MAX 100

int matrix[MAX][MAX];
char labels[MAX];
int n;

int key[MAX];
int parent[MAX];
bool mstSet[MAX];

int extractMin(int key[], bool mstSet[], int n) {
    int min = INT_MAX , minIndex = -1;
    for(int i=0;i<n;i++){
        if(mstSet[i]==false && key[i]<min){
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void Prims(int W[MAX][MAX],int root , int n){
    for(int i=0;i<n;i++){
        key[i] = INT_MAX;
        mstSet[i] = false;  
        parent[i] = -1;
    }
    key[root]=0;
    for(int count=0;count<n-1;count++){
        int u = extractMin(key,mstSet,n);
        mstSet[u] = true;
        for(int v=0;v<n;v++){
            if(W[u][v] && mstSet[v]==false && W[u][v]<key[v]){
                parent[v] = u;
                key[v] = W[u][v];
            }
        }
    }
}

int main(){
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("Enter the labels of the vertices:\n");
    for(int i=0;i<n;i++){
        scanf(" %c",&labels[i]);
    }
    Prims(matrix,0,n);
    printf("Minimum Spanning Tree:\n");
    for(int i=1;i<n;i++){
        printf("%c -- %c == %d\n",labels[parent[i]],labels[i],matrix[i][parent[i]]);
    }
    return 0;
}