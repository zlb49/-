#include<iostream>
const int MAX_SIZE = 110;
using namespace std;
int main() {
	int	m, n,//mΪ��Ͷ�ʽ�nΪͶ����Ŀ����
		start[100][100],//��ʼ����������
		localmax[100][100] = { 0 },//�ֲ��������
		end[100][100]; //��¼����Ͷ�ʷ���
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
					end[i][j] = k;//����ǰ��������¼����
				}
			}
		}
	}
	cout << "������棺" <<endl<< localmax[n][m] << "���䷽�����£�" << endl;
	int t = m;
	for (int i = n; i >= 1; i--) 
	{
		cout << "�������" << i << "����Ŀ" << end[i][t] << "��" << endl;
		t -= end[i][t];
	}
}

