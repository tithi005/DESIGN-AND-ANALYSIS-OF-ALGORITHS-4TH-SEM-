#include<stdio.h>
#include<stdlib.h>
struct edge{
    int u;
    int v;
    int w;
};
int tree[100][3];
int noTE;
struct edge E[] = {{0, 1, 2}, {1, 2, 3}, {2, 5, 3}, {5, 4, 3}, {4, 3, 4}, {3, 0, 2}, {3, 1, 2}, {3, 2, 1}, {4, 2, 3}};
int NOV = 6;
int NOE = 9;
void partition(struct edge E[], int low, int high, int *i, int *j){
    struct edge pivot, temp;
    pivot = E[high];
    *i = low-1;
    for(*j = low; *j <= high-1; (*j)++){
        if(E[*j].w < pivot.w){
            (*i)++;
            temp = E[*i];
            E[*i] = E[*j];
            E[*j] = temp;
        }
    }
    (*i)++;
    temp = E[*i];
    E[*i] = E[high];
    E[high] = temp;
}

void quicksort(struct edge E[], int low, int high){
    int i, j;
    if(low < high){
        partition(E, low, high, &i, &j);
        quicksort(E, low, i-1);
        quicksort(E, i+1, high);
    }
}
showGraph(){
    for(int i = 0; i < NOE; i++){
        printf("%c -- %c == %d\n", E[i].u+65, E[i].v+65, E[i].w);
    }
}

int parent[100];
void makeset(int n){
    for(int i = 0; i < n; i++){
        parent[i] = -1;
    }
}
void union1(int i, int j){
    parent[j] = i;
}
void find(int i, int *p){
    if(parent[i] == -1){
        *p = i;
        return;
    }
    find(parent[i], p);
}
void Kruskal(){
    makeset(NOV);
    noTE = 0;
    for(int i = 0; i < NOE; i++){
        int u = E[i].u;
        int v = E[i].v;
        int p1, p2;
        find(u, &p1);
        find(v, &p2);
        if(p1 != p2){
            tree[noTE][0] = u;
            tree[noTE][1] = v;
            tree[noTE][2] = E[i].w;
            noTE++;
            union1(p1, p2);
        }
    }
}

void showTree(){
    int cost = 0;
    printf("The edges in the minimum spanning tree are:\n");
    for(int i = 0; i < noTE; i++){
        printf("%c -- %c == %d\n", tree[i][0]+65, tree[i][1]+65, tree[i][2]);
        cost += tree[i][2];
    }
    printf("The cost of the minimum spanning tree is: %d\n", cost);
}
 int main(){
    printf("The edges in the graph are:\n");
    showGraph();
    quicksort(E, 0, NOE-1);
    printf("The edges in the graph after sorting are:\n");
    showGraph();
    Kruskal();
    showTree();
    return 0;
}    