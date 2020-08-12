#include <stdio.h>
#include <malloc.h>
#include <string.h>


char a[50], b[50], m, n;
int ** C;

int LCS(int m, int n);
int max(int x, int y);

int main() {
    scanf("%s", &a);
    scanf("%s", &b);
	m = strlen(a);
	n = strlen(b);
	
    C = (int ** )malloc(sizeof(int*) * m+1);
    for (int i = 0; i < m+1; i++) {
        C[i] = (int *)malloc(sizeof(int) * n+1);
    }
 
	printf("%d", LCS(m, n));
	return 0;
}

int LCS(int m, int n) {
    for (int i = 0; i <= m; i++)
        C[i][0] = 0;
    for (int j = 0; j <= n; j++)
        C[0][j] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if(a[i-1]==b[j-1]) 
				C[i][j] = C[i - 1][j - 1] + 1;
            else 
				C[i][j] = max(C[i - 1][j], C[i][j - 1]);
        }
    }
    return C[m][n];
}

int max(int x, int y)
{
   if(x > y)
      return x;
   else 
	   return y;
}
