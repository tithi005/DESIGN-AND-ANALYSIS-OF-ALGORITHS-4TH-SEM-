#include<stdio.h>
#define MAX 10
int G[MAX][MAX];
int x[MAX];
int n;
int m;
int solutioncount=0;

void NextValue(int k){
    int j;
    do{
        x[k] = (x[k]+1)%(m+1);
        if(x[k] == 0) return;
        for(j=1;j<=n;j++){
            if(G[k][j]!=0 && x[k]== x[j])
                break;
        }
        if(j==n+1)return;
    } while(1);
}

void mcolouring(int k){
    do{
        NextValue(k);
        if(x[k]==0) return;
        if(k==n){
            solutioncount++;
            printf("\nSolution %d:\n",solutioncount);
            for(int i=1;i<=n;i++)
                printf("Vertex %d ---> Color %d\n",i,x[i]);
        }
        else
            mcolouring(k+1);
    } while(1);
}

int main(){
    int i,j;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&G[i][j]);
        }
    }
    printf("Enter the number of colors: ");
    scanf("%d",&m);
    for(i=1;i<=n;i++)
        x[i]=0;
    mcolouring(1);
    if(solutioncount==0)
        printf("\nNo solution exists.\n");
    return 0;
}