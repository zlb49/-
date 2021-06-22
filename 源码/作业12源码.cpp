#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int color[100];
bool is(int k, int graph[][100]) {//�ж϶���k����ɫ�Ƿ�����ͻ
	int i;
	for (i = 1; i < k; i++)
		if (graph[k][i] == 1 && color[i] == color[k])
			return false;
	return true;
}

void getGraph(int n, int m, int graph[][100]) {
	int i, k;
	int flag = 0;
	for (i = 1; i <= n; i++) {
		color[i] = 0;//��ȫ����ʼ��Ϊ0
	}
	k = 1;
	while (k >= 1) {
		color[k] = color[k] + 1;
		while (color[k] <= m) {
			if (is(k, graph))//�ж��Ƿ��ͻ
				break;//��ͻ������
			else
				color[k] = color[k] + 1;//����ͻ��������һ����ɫ
		}
		if (color[k] <= m && k == n) {//����������
			for (i = 1; i <= n; i++) {
				printf("%d ", color[i]);
			}
			printf("\n");
			flag = 1;
		}
		else if (color[k] <= m && k < n) {
			k = k + 1;//������һ������
		}
		else {
			color[k] = 0;
			k = k - 1;//����
		}
	}
	if (flag == 1) {//���������NO
		printf("NO\n");
	}
}

int main() {
	int i, j, n, m;
	int graph[100][100];
	printf("�����붥����n����ɫ��m��\n");
	scanf("%d%d", &n, &m);
	printf("����������ͼ���ڽӾ���\n");
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	printf("��ɫ���ܽ�m��\n");
	getGraph(n, m, graph);
	return 0;
}
