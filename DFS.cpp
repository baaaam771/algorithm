#include <stdio.h>
#include <malloc.h>
 
int n, m;
int ** e, * q;
int * visited, count = 0;
void DFS(int s);
void aDFS(int s);
 
int main(void) {
    int x, y, s;
    scanf("%d", &n);
    scanf("%d", &m);
    n++;
    q = (int*)malloc(sizeof(int) * n-1);
    e = (int**)malloc(sizeof(int*) * n);
    for(int i=0; i < n; i++)
        e[i] = (int *)malloc(sizeof(int) * n);
    for(int i=0; i < n; i++)
        for(int j=0; j < n; j++)
            e[i][j] = 0;
    for(int i=0; i<m; i++) {
        scanf("%d", &x);
        scanf("%d", &y);
        e[x][y] = 1;
        e[y][x] = 1;
    }
    scanf("%d", &s);
    DFS(s);
    for(int i= 0; i < n-1; i++)
        printf("%d ", q[i]);
    return 0;
}
 
void DFS(int s) {
    visited = (int*)malloc(sizeof(int) * n);
    for(int i=0; i< n; i++)
        visited[i] = 0;
    visited[s] = 1;
    q[count++] = s;
     
	for(int i=1; i< n; i++) {
		if(e[s][i] == 1 && visited[i] == 0) {
			aDFS(i);
		}
	}
}

void aDFS(int v) {
	visited[v] = 1;
	q[count++] = v;
    for(int i=1; i< n; i++) {
        if(e[v][i] == 1 && visited[i] == 0) {
            aDFS(i);
        }
    }
}
