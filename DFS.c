#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int matrix[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

int isEmpty(){
    return top == -1;
}

void push(int val){
    stack[++top]= val;
}

int pop(){
    if(isEmpty()) return -1;
    return stack[top--];
}

void DFSTraversal(int n,int v){
    for(int u = 0;u<n;u++){
        visited[u]= 0;
    }
    push(v);
    while(!isEmpty()){
        int u = pop();
        if(visited[u]== 0){
            visited[u] = 1;
            printf("%d\t",u);
            for(int j = 0; j<n ; j++){
                if(matrix[u][j]==1 && visited[j]==0){
                    push(j);
                }
            }
        }
    }
}

void DFSrecursive(int v){
    visited[v] = 1;
    printf("%d\t",v);
    for(int j = 0;j<n;j++){
        if(matrix[v][j]==1 && visited[j]==0){
            DFSrecursive(j);
        }
    }
}

int main(){
    FILE *fp = fopen("graph.txt","r");
    if(fp == NULL){
        printf("ERROR : COULDNOT OPEN THE FILE\n");
        exit(0);
    }
    fscanf(fp , "%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fscanf(fp , "%d", &matrix[i][j]);
        }
    }
    fclose(fp);
    int v;
    printf("Enter the starting vertex(0 to %d): ",n-1);
    scanf("%d",&v);
    DFSTraversal(n,v);
    DFSrecursive(v);
    printf("\n");
    return 0;
}