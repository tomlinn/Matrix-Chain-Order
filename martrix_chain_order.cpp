#include <stdio.h>
#include <stdlib.h>
#define N 100
#define MAX 1000000
int m[N][N], s[N][N],x=1;
void matrixChainOrder(int *p, int n) {
	int i, j, l, k, temp;
	for(i = 1; i < n; i++)
		m[i][i] = 0;
	for(l = 2; l < n; l++) {
		for(i = 1; i < n - l + 1; i++) {
			j = i + l - 1;
			m[i][j] = MAX;
			for(k = i; k < j; k++) { //所有切的可能
				temp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if(temp < m[i][j]) {
					m[i][j] = temp;
					s[i][j] = k;
				}
			}
		}
	}
	printf("m\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			
			
				printf("%2d ",m[i][j]);
			
		}
		printf("\n");
	}
	printf("s\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			
			
				printf("%2d ",s[i][j]);
			
		}
		printf("\n");
	}
	printf("The number of required multiplications:%d\n",m[1][n-1]);
}
void printOptimalParens(int s[N][N], int i, int j) {
	
	if(i == j){
		printf("A%d",x);
		x++;
	}
	else {
		printf("(");
		printOptimalParens(s, i, s[i][j]);
		printOptimalParens(s, s[i][j] + 1, j);
		printf(")");
	}
}
int main() {
	int i, n, p[N];
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&p[i]);
	}
	matrixChainOrder(p, n);
	printOptimalParens(s, 1, n - 1);
	system("pause");
	return 0;
}