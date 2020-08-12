#include<stdio.h>
#include <limits.h>
#include <malloc.h> 
#define INF 1000000

int n,m,*t,i,j;
int e[100][100];
int vi[100];
int dijkstra[100];
int start, end;

void Dijkstra();

int main() 
{
    int x, y, w;
	int k = 1;
    scanf("%d", &n);
    scanf("%d", &m);
	t=(int*)malloc(sizeof(int)*n+1);

	for(i=1; i<= n; i++){
		t[i] = 0;
	}
	for(i=1; i <= n; i++)
		for(j=1; j <= n; j++)
			if(i!=j)
				e[i][j]=INF;
		
	for(i=0; i < m; i++){
		scanf("%d %d %d",&x,&y,&w);
		if(t[y] == 0 && k<=n){
			t[y] = x;
			k++;
		}
		e[x][y] = w;
	}
	scanf("%d %d",&start,&end);
	for (i=1; i <= n; i++){
		dijkstra[i]=INF;
	}
	Dijkstra();
	t[start] = 0;
   
	for(int i=1; i <= n; i++) {
		printf("%d ", t[i]);
	}   
	if(dijkstra[end] != INF) 
		printf("%d", dijkstra[end]);
	else 
		printf("Impossible");
}


void Dijkstra() {
	int min, v;
	dijkstra[start] = 0;
	for(i=1; i <= n; i++){
		min = INF;
		for(j=1; j <= n; j++){
			if(vi[j] == 0 && min > dijkstra[j]){
				min = dijkstra[j];
				v = j;
			} 
		}
		vi[v] = 1;
		for(j=1; j <= n; j++){
			if(dijkstra[j] > dijkstra[v] + e[v][j]){
				t[j] = v;
				dijkstra[j] = dijkstra[v] + e[v][j];
			}
		}
	}
}
