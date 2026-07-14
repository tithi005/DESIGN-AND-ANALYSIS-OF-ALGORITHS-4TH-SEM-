#include<stdio.h>
#include<stdlib.h>
#define max 101
int n;
float p[max] , w[max] , x[max];

void SortByRatio(){
    int i, j;
    float tempP, tempW;
    for(i = 1; i <= n-1; i++){
        for(j = 1; j <= n - i; j++){
            if( (p[j]/w[j]) < (p[j+1]/w[j+1]) ){
                tempP = p[j]; p[j] = p[j+1]; p[j+1] = tempP;
                tempW = w[j]; w[j] = w[j+1]; w[j+1] = tempW;
            }
        }
    }
}

void FractionalKnapsack(float m){
    float u;
    int i;
    u = m;
    for(i = 1; i<=n ; i++)
        x[i] = 0.0;
    for(i = 1;i<=n;i++){
        if(w[i]>u)
            break;
        x[i] = 1.0;
        u = u-w[i];
    }
    if(i<=n){
        x[i] = u/w[i];
    }
}

int main(){
    float m; int i;float totalProfit = 0.0;
    printf("\n Enter the number of items:");
    scanf("%d",&n);
    printf("\nEnter the profit: ");
    for(i=1;i<=n;i++){
        printf("p[%d]= ",i);
        scanf("%f",&p[i]);
    }

    printf("\nEnter the weight: ");
    for(i=1;i<=n;i++){
        printf("w[%d]= ",i);
        scanf("%f",&w[i]);
    }

    printf("\nEnter the Knapsack capacity:");
    scanf("%f",&m);

    SortByRatio();
    FractionalKnapsack(m);
    printf("Items\tProfit\tWeight\tSolution\n");
    for(i=1;i<=n;i++){
        printf("%c\t%.1f\t%.1f\t%.2f\n",'A'+i-1,p[i],w[i],x[i]);
        totalProfit += x[i]*p[i];
    }

    printf("\nThe total profit is:%.2f",totalProfit);

    return 0;
}