#include <stdio.h>
#include <limits.h>
#define MAX 20

int p[MAX];        
int m[MAX][MAX];  
int s[MAX][MAX];  
int n;            
void matrixChainOrder(){
    for(int i = 1; i <= n; i++){
        m[i][i] = 0;
    }

    for(int l = 2; l <= n; l++){
        for(int i = 1; i <= n - l + 1; i++){
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for(int k = i; k <= j - 1; k++){
                int cost = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                if(cost < m[i][j]){
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
}

// print the optimal parenthesization using s[][]
void printOptimalParens(int i, int j){
    if(i == j){
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParens(i, s[i][j]);
        printOptimalParens(s[i][j]+1, j);
        printf(")");
    }
}

int main(){
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions p[0..%d] (p[i-1] x p[i] = dims of matrix i):\n", n);
    for(int i = 0; i <= n; i++){
        scanf("%d", &p[i]);
    }

    matrixChainOrder();

    printf("\nMinimum number of multiplications: %d\n", m[1][n]);

    printf("Optimal parenthesization: ");
    printOptimalParens(1, n);
    printf("\n");

    return 0;
}