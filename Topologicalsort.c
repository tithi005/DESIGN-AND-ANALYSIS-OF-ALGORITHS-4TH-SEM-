#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int matrix[MAX][MAX];
int inDegree[MAX];
int queue[MAX],front = 0 , rear = 0;
int result[MAX];
char labels[MAX];
int n;

int isEmpty(){
    return front == rear || front> rear;
}
void enqueue(int val){
    queue[rear++] = val;
}

int dequeue(){
    if(isEmpty()) return -1;
    return queue[front++];
}

void TopologicalSort(){
    for(int i = 0;i<n;i++){
        inDegree[i] = 0;
    }
    for(int i=0 ; i<n ; i++){
        for(int j = 0;j<n;j++){
            inDegree[j]= inDegree[j]+matrix[i][j];
        }
    }
    for(int u = 0;u<n;u++){
        if(inDegree[u]==0){
            enqueue(u);
        }
    }
    int count = 0;
    while(!isEmpty()){
        int u = dequeue();
        result[count++]=u;
        for(int w=0;w<n;w++){
            if(matrix[u][w]==1){
                inDegree[w]--;
                if(inDegree[w]==0){
                    enqueue(w);
                }
            }
        }
    }
    if(count!=n){
        printf("G has cycle.....Topological sort not possible!\n");
    } else{
        printf("Topological sort order:");
        for(int i = 0;i<count;i++){
            printf("%c",labels[result[i]]);
        }
        printf("\n");
    }
}

int main(){
    FILE *fp = fopen("graph.txt","r");
    if(fp==NULL){
        printf("Error! couldnot open the graph\n");
    }
    fscanf(fp , "%d" , &n);
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            fscanf(fp , "%d" , &matrix[i][j]);
        }
    }
    fclose(fp);
    for(int i=0;i<n;i++){
        labels[i] = 'A'+i;
    }

    TopologicalSort();
    return 0;
}