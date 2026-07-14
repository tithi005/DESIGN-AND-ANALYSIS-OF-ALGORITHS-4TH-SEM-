#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int n;
bool slot[50];
int d[50];
int x[50];
float p[50];

void SortByProfit(){
    int i,j,tempD;
    float tempP;
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){
            if(p[j]<p[j+1]){
                tempP=p[j];p[j] = p[j+1] ; p[j+1]=tempP;
                tempD=d[j] ; d[j]=d[j+1] ; d[j+1] = tempD;
            }
        }
    }
}

void JSD(int n){
    int i,j;
    for(i=1;i<=n;i++){
        x[i]=0;
        slot[i]= false;
    }

    for(i = 1;i<n;i++){
        for(j=(d[i]<n ? d[i]:n);j>=1;j--){
            if(slot[j]== false){
                slot[j]=true;
                x[j] = i;
                break;
            }
        }
    }
}

int main(){
    float profit = 0;
    int i;
    printf("\n enter the number of jobs:");
    scanf("%d",&n);
    printf("\nEnter the profit: ");
    for(i=1;i<=n;i++){
        printf("p[%d]= ",i);
        scanf("%f",&p[i]);
    }
    printf("\nEnter the deadline: ");
    for(i=1;i<=n;i++){
        printf("d[%d]= ",i);
        scanf("%d",&d[i]);
    }
    SortByProfit();
    JSD(n);
    printf("Job\tProfit\tDeadline\tSolution\n");
    for(i=1;i<=n;i++){
        if(x[i]!=0){
            profit += p[x[i]];
            printf("%c\t%.1f\t%d\t\t%c\n",'A'+x[i]-1,p[x[i]],d[x[i]],'A'+x[i]-1);
        }
    }
    printf("Total Profit: %.1f\n", profit);
}