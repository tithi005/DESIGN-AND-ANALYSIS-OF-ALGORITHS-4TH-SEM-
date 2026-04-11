#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void maxmin(int a[], int i, int j, int *max, int *min){
    int max1, min1, mid,count = 0;
    if(i == j){
        *max = *min = a[i];
    }
    else if(i == j - 1){
        if(a[i] < a[j]){
            *max = a[j];
            *min = a[i];
        } else {
            *max = a[i];
            *min = a[j];
        }
    }
    else{
        mid = (i + j) / 2;
        maxmin(a, i, mid, &max1, &min1);
        maxmin(a, mid + 1, j, max, min);
        if(*max < max1)
            *max = max1;
        if(*min > min1)
            *min = min1;
    }
}

int main(){
    srand(time(0));
    int n;
    int max;
    int min;

    printf("\nEnter the size of the array:");
    scanf("%d", &n);
    int a[n];

    for(int i = 0; i < n; i++){
        a[i] = rand() % 100;
    }
    for(int i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }

    maxmin(a, 0, n - 1, &max, &min);
    printf("\nThe maximum value is :%d", max);
    printf("\nThe minimum value is :%d", min);
}