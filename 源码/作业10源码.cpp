#include <algorithm>
#include <iostream> 
#include<stdio.h>
#define maxn 100
using namespace std;
int n, c;
void Knapsack(int* v, int* w, int c, int n, int(*m)[maxn]) {
	//���жϵ�n����Ʒ�ܲ���װ�뱳��
	int jMax = min(w[n] - 1, c);
	//��0<=j<=wnʱ��m(n��j)=0
	for (int j = 0; j <= jMax; j++) {
		m[n][j] = 0;
	}
	//��j>=wnʱ��m(n��j)=vn
	for (int j = w[n]; j <= c; j++) {
		m[n][j] = v[n];
	}
	//�ٴ�n-1��ǰ��ʼ�жϵ�n����Ʒ����i����Ʒ�ܲ���װ��
	for (int i = n - 1; i > 1; i--) {
		jMax = min(w[i] - 1, c);
		for (int j = 0; j < jMax; j++) {
			m[i][j] = m[i + 1][j];
		}
		for (int j = w[i]; j <= c; j++) {
			m[i][j] = max(m[i + 1][j], m[i + 1][j - w[i]] + v[i]);
		}

	}
	//�жϵ�n������1����Ʒ�ܲ���װ��
	m[1][c] = m[2][c];
	if (c >= w[1])
		m[1][c] = max(m[1][c], m[2][c - w[1]] + v[1]);
}

//���ݲ����������У���װ�µĸ�ֵΪ1������װ�µĸ�ֵΪ0
void Traceback(int(*m)[maxn], int* w, int c, int n, int* x) {
	for (int i = 1; i < n; i++) {
		if (m[i][c] == m[i + 1][c])
			x[i] = 0;
		else {
			x[i] = 1;
			c -= w[i];
		}
	}
	x[n] = (m[n][c]) ? 1 : 0;
}

int main() {
	//������������

	cout << "�����뼯װ������ n=";
	cin >> n;
	cout << "�������ִ����� c=";
	cin >> c;
	int w[maxn];
	cout << "�������������װ���������";
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	int v[maxn];
	cout << "�������������װ��ļ�ֵ��";
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	int m[maxn][maxn];
	int x[maxn];
	int max_weight = 0;
	int max_value = 0;
	//���в��������
	Knapsack(v, w, c, n, m);
	Traceback(m, w, c, n, x);
	//����������к��������������ż�ֵ
	cout << "����װ������Ϊ��\n";
	for (int i = 1; i <= n; i++) {
		cout << x[i];
		max_weight += (x[i] * w[i]);
		max_value += (x[i] * v[i]);
	}
	cout << endl;
	cout << "�������Ϊ�� " << max_weight << endl << "����ֵΪ�� " << max_value << endl;
	return 0;
}
