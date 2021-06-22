#include <stdio.h>
void print(int s[][100],int i,int j) {//括号化方案
	if (i == j){
		printf("A%d",i);
	}
	else{
		printf("(");
		print(s, i, s[i][j]);
		print(s, s[i][j] + 1, j);
		printf(")");
	}
}
void MatrixChain(int p[100],int m[100][100],int s[100][100],int n){
	int r,i,j,k,t;
	for (r = 2; r <= n; r++) {//r为当前问题规模（长度）
		for (i = 1; i <= n-r+1; i++) { //i的起点不断变化，各种r长
			j = i+r-1;  //不同终点
			m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];//划分为Ai(Ai+1...Aj),此时k=i
			s[i][j] = i;//初始化 s位置为i 
			for (k = i+1; k <= j - 1; k++){
				t = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if (t < m[i][j]){
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
}
int main(){
	int p[100],m[100][100],s[100][100],n,i;
	printf("输入问题规模（长度）: ");
	scanf("%d", &n);
	printf("输入向量: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	MatrixChain(p, m,s, n-1);
	printf("最小总次数为: %d\n",m[1][n-1]);
	printf("括号化方案为：");
	print(s, 1, n-1);
}
