#include<stdio.h>
#include<stdlib.h>
int main()
{
	int e[10][10], k, i, j, n, m, t1, t2, t3;
	int inf = 0x3f3f3f; //��inf�洢һ��������Ϊ���������ֵ
	scanf("%d %d", &n, &m); //n��ʾ���������m��ʾ�ߵ�����

	for (i = 1; i <= n; i++)//��ʼ�� 
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = inf;
		}
	}

	for (i = 1; i <= m; i++)//�����
	{
		scanf("%d %d %d", &t1, &t2, &t3);
		e[t1][t2] = t3; //��ʾ t1 �� t2 ��·��Ϊ t3  ,���������ͼ������ֻ��Ҫ��ֵһ�����ɣ���������ͼ�������Ҫ��ֵ����
		//e[t1][t2] =e[t2][t1] = t3  ����ͼ
	}

	for (k = 1; k <= n; k++) //Floyd-Warshall�㷨 �����������k
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (e[i][j] > e[i][k] + e[k][j])//���������������ת��ԭ��ֱ��ȥ�ľ�����Ƚϣ�������̾ͽ��и���
				{
					e[i][j] = e[i][k] + e[k][j];
				}
			}
		}
	}

	for (i = 1; i <= n; i++)//����������
	{
		for (j = 1; j <= n; j++)
		{
			printf("%5d", e[i][j]);
		}
		printf("\n");
	}
	return 0;
}

