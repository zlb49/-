#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int color[100];
bool is(int k, int graph[][100]) {//判断顶点k的着色是否发生冲突
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
		color[i] = 0;//先全部初始化为0
	}
	k = 1;
	while (k >= 1) {
		color[k] = color[k] + 1;
		while (color[k] <= m) {
			if (is(k, graph))//判断是否冲突
				break;//冲突啧跳出
			else
				color[k] = color[k] + 1;//不冲突则搜索下一个颜色
		}
		if (color[k] <= m && k == n) {//输出符合情况
			for (i = 1; i <= n; i++) {
				printf("%d ", color[i]);
			}
			printf("\n");
			flag = 1;
		}
		else if (color[k] <= m && k < n) {
			k = k + 1;//处理下一个顶点
		}
		else {
			color[k] = 0;
			k = k - 1;//回溯
		}
	}
	if (flag == 1) {//不存在输出NO
		printf("NO\n");
	}
}

int main() {
	int i, j, n, m;
	int graph[100][100];
	printf("请输入顶点数n和着色数m：\n");
	scanf("%d%d", &n, &m);
	printf("请输入无向图的邻接矩阵：\n");
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	printf("着色可能解m：\n");
	getGraph(n, m, graph);
	return 0;
}
