#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int matrix[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0 ,rear = 0;
int n;

int isEmpty(){
    return front==rear || front> rear;
}
void enqueue(int val){
    queue[rear++]= val;
}

int dequeue(){
    if(isEmpty()) return -1;
    return queue[front++];
}

void BFSTraversal(int n , int v){
    for(int u=0;u<n;u++){
        visited[u]=0;
    }
    front = rear = 0;
    visited[v]=1;
    enqueue(v);
    while(!isEmpty()){
        int u = dequeue();
        printf("%d\t",u);
        for(int j =0 ; j<n;j++){
            if(matrix[u][j]==1 && visited[j]==0){
                visited[j]=1;
                enqueue(j);
            }
        }
    }

}

int main(){
    FILE *fp = fopen("graph.txt","r");
    if(fp == NULL){
        printf("Error:couldnot open graph.txt\n");
    }
    fscanf(fp, "%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fscanf(fp,"%d",&matrix[i][j]);
        }
    }
    fclose(fp);

    int v;
    printf("\nEnter the starting vertex(0 to %d)",n-1);
    scanf("%d",&v);
    BFSTraversal(n,v);
    printf("\n");
    return 0;
}