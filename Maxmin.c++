#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int count = 0;
void maxmin(int a[], int i, int j, int *max, int *min){
    int max1, min1, mid;
    if(i == j){
        *max = *min = a[i];
    }
    else if(i == j - 1){
        count++;
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
        maxmin(a, i, mid, max, min);
        maxmin(a, mid + 1, j, &max1, &min1);
        count = count +2 ;
        if(*max < max1){
            *max = max1;
        }
        if(*min > min1){
            *min = min1;
        }
    }
}
int main(){
    srand(time(0));
    int n;
    int max;
    int min;

    cout<<"\nEnter the size of the array:";
    cin>>n;
    int a[n];

    for(int i = 0; i < n; i++){
        a[i] = rand() % 100;
    }
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }

    maxmin(a, 0, n - 1, &max, &min);
    cout<<"\nThe maximum value is :"<<max;
    cout<<"\nThe minimum value is :"<<min;
    cout<<"\nThe number of comparisons is "<<count;
    return 0;
}