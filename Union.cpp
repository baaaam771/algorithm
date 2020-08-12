#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <malloc.h>

int n, m;
int i,j,v,u;
int *pf, ** e;

int FindSet(int i);
int Union(int i,int j);

int main()
{
    int x, y, w, s = 1, sum = 0, min = INT_MAX;
    scanf("%d", &n);
    scanf("%d", &m);
	n++;
	pf = (int *)malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++)
		pf[i] = 0;
    e = (int **)malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++)
        e[i] = (int *)malloc(sizeof(int) * n);
    for(int i=0; i < n; i++)
        for(int j=0; j < n; j++)
            e[i][j] = INT_MAX;
	
    for(int i=0; i<m; i++) {
        scanf("%d", &x);
        scanf("%d", &y);
        scanf("%d", &w);
        e[x][y] = w;
        e[y][x] = w;
    }

	while(s < n-1){
		min=INT_MAX;
		for(i=1; i < n; i++){
			for(j=1; j < n; j++){
				if(e[i][j] < min){
					min=e[i][j];
					x=i; y=j;
				}
			}
		}
		u=FindSet(x);
		v=FindSet(y);
		if(Union(u,v)){
			s++;
			printf("%d ",min);
			sum +=min;
		}
		e[x][y] = INT_MAX;
		e[y][x] = INT_MAX;
	}
	printf("%d",sum);
	return 0;
}

int FindSet(int i) {
	while(pf[i]){
		i=pf[i];
	}
	return i;
}

int Union(int i,int j) {
	if(i != j){
		pf[j] = i;
		return 1;
	}
	return 0;
}
