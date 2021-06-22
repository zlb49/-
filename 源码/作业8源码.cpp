#include <stdio.h>
void print(int s[][100],int i,int j) {//���Ż�����
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
	for (r = 2; r <= n; r++) {//rΪ��ǰ�����ģ�����ȣ�
		for (i = 1; i <= n-r+1; i++) { //i����㲻�ϱ仯������r��
			j = i+r-1;  //��ͬ�յ�
			m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];//����ΪAi(Ai+1...Aj),��ʱk=i
			s[i][j] = i;//��ʼ�� sλ��Ϊi 
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
	printf("���������ģ�����ȣ�: ");
	scanf("%d", &n);
	printf("��������: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	MatrixChain(p, m,s, n-1);
	printf("��С�ܴ���Ϊ: %d\n",m[1][n-1]);
	printf("���Ż�����Ϊ��");
	print(s, 1, n-1);
}
