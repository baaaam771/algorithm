#include <stdio.h>
#include <limits.h>
#include <malloc.h>
 
int n, m;
int ** e;
int count = 0;
void prim(void);
int extactMin(int d[], int check[]);
void sumMST(int p[]);
 
int main(void) {
    int x, y, w, s;
    scanf("%d", &n);
    scanf("%d", &m);
    e = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++)
        e[i] = (int *)malloc(sizeof(int) * n);
    for(int i=0; i < n; i++)
        for(int j=0; j < n; j++)
            e[i][j] = 0;
    for(int i=0; i<m; i++) {
        scanf("%d", &x);
        scanf("%d", &y);
        scanf("%d", &w);
		x--; y--;
        e[x][y] = w;
        e[y][x] = w;
    }
    prim();
    return 0;
}
 
void prim(void) {
	int r = 0, u, *p, *d, *check;
    p = (int*)malloc(sizeof(int) * n);
    d = (int*)malloc(sizeof(int) * n);
    check = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i< n; i++) {
        d[i] = INT_MAX;
		check[i] = 0;
	}
	p[r] = -1;
	d[r] = 0;

	
	for(int i=0; i< n; i++) {
		u = extactMin(d, check);
		check[u] = 1;
		for(int i=0; i< n; i++) {
			if(e[u][i] != 0 && e[u][i] < d[i] && check[i] == 0) {
				p[i] = u;
				d[i] = e[u][i];
			}
		}
	}
	sumMST(p);
}

int extactMin(int d[], int check[]) {
	int m = INT_MAX, result;
    for(int i=0; i< n; i++) {
        if(check[i] == 0 && d[i] < m) {
            m = d[i];
			result = i;
        }
    }
	printf("%d ", result+1);
	return result;
}

void sumMST(int p[])
{
	int sum=0;
	for (int i = 1; i < n; i++){
		sum = sum + e[i][p[i]];
	}
	printf("%d",sum);
}
