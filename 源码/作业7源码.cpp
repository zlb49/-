#include<iostream>
const int MAX_SIZE = 110;
using namespace std;
int main() {
	int	m, n,//m为总投资金额，n为投资项目总数
		start[100][100],//初始给出的收益
		localmax[100][100] = { 0 },//局部最大收益
		end[100][100]; //记录最终投资方案
	cin >> m >> n;
	for (int i = 0; i <= m; i++) 
	{
		for (int j = 1; j <= n; j++) 
		{
			cin>>start[j][i];
		}
	}
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= m; j++) 
		{
			for (int k = 0; k <= j; k++) 
			{
				if (localmax[i][j] <= localmax[i - 1][j - k] + start[i][k]) 
				{
					localmax[i][j] = localmax[i - 1][j - k] + start[i][k];
					end[i][j] = k;//将当前最大收益记录下来
				}
			}
		}
	}
	cout << "最大收益：" <<endl<< localmax[n][m] << "分配方案如下：" << endl;
	int t = m;
	for (int i = n; i >= 1; i--) 
	{
		cout << "分配给第" << i << "个项目" << end[i][t] << "万" << endl;
		t -= end[i][t];
	}
}

