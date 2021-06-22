#include <algorithm>
#include <iostream> 
#include<stdio.h>
#define maxn 100
using namespace std;
int n, c;
void Knapsack(int* v, int* w, int c, int n, int(*m)[maxn]) {
	//先判断第n个物品能不能装入背包
	int jMax = min(w[n] - 1, c);
	//当0<=j<=wn时，m(n，j)=0
	for (int j = 0; j <= jMax; j++) {
		m[n][j] = 0;
	}
	//当j>=wn时，m(n，j)=vn
	for (int j = w[n]; j <= c; j++) {
		m[n][j] = v[n];
	}
	//再从n-1往前开始判断第n个物品到第i个物品能不能装下
	for (int i = n - 1; i > 1; i--) {
		jMax = min(w[i] - 1, c);
		for (int j = 0; j < jMax; j++) {
			m[i][j] = m[i + 1][j];
		}
		for (int j = w[i]; j <= c; j++) {
			m[i][j] = max(m[i + 1][j], m[i + 1][j - w[i]] + v[i]);
		}

	}
	//判断第n个到第1个物品能不能装下
	m[1][c] = m[2][c];
	if (c >= w[1])
		m[1][c] = max(m[1][c], m[2][c - w[1]] + v[1]);
}

//回溯查找最优序列，能装下的赋值为1，不能装下的赋值为0
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
	//进行数据输入

	cout << "请输入集装箱数量 n=";
	cin >> n;
	cout << "请输入轮船容量 c=";
	cin >> c;
	int w[maxn];
	cout << "请依次输入各集装箱的重量：";
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	int v[maxn];
	cout << "请依次输入各集装箱的价值：";
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	int m[maxn][maxn];
	int x[maxn];
	int max_weight = 0;
	int max_value = 0;
	//进行查找与回溯
	Knapsack(v, w, c, n, m);
	Traceback(m, w, c, n, x);
	//输出最优序列和最优重量与最优价值
	cout << "最优装载序列为：\n";
	for (int i = 1; i <= n; i++) {
		cout << x[i];
		max_weight += (x[i] * w[i]);
		max_value += (x[i] * v[i]);
	}
	cout << endl;
	cout << "最大重量为： " << max_weight << endl << "最大价值为： " << max_value << endl;
	return 0;
}
