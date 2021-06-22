#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct//节点类型
{
	int weight;//结点的权值
	int parent, lChild, rChild;//双亲指针及左右孩子
}HTNode, * HuffmanTree;

typedef struct
{
	char** code;//存放编码位串，这儿code即为数组
	int n;//编码数
}HuffmanCode;

void SelectMin(HuffmanTree hT, int n, int& s1, int& s2);
void CreateHufmanTree(HuffmanTree& hT);
void CreateHuffmanCode(HuffmanTree hT, HuffmanCode& hC);
void PrintHuffmanCode(HuffmanCode& hC);

int main()
{
	HuffmanTree hT;
	CreateHufmanTree(hT);
	HuffmanCode hC;
	CreateHuffmanCode(hT, hC);
	PrintHuffmanCode(hC);
	return 0;
}
void SelectMin(HuffmanTree hT, int n, int& s1, int& s2)//在前k个结点中选择权值最小和次小的根结点，其序号分别为s1和s2
{
	s1 = s2 = 0;
	int i;
	for (i = 1; i < n; ++i) {//寻找最小和次小根节点的过程
		if (0 == hT[i].parent) {
			if (0 == s1) {
				s1 = i;
			}
			else {
				s2 = i;
				break;
			}
		}
	}
	if (hT[s1].weight > hT[s2].weight) {
		int t = s1;
		s1 = s2;
		s2 = t;
	}

	for (i += 1; i < n; ++i) {//对weight按照权值从小到打排序
		if (0 == hT[i].parent) {
			if (hT[i].weight < hT[s1].weight) {
				s2 = s1;
				s1 = i;
			}
			else if (hT[i].weight < hT[s2].weight) {
				s2 = i;
			}
		}
	}
}

void CreateHufmanTree(HuffmanTree& hT)//构造有n个权值（叶子节点）的哈夫曼树
{
	int n, m;
	cout << "请输入一共有几个点：";
	cin >> n;
	m = 2 * n - 1;//总节点数

	hT = new HTNode[m + 1];    // 0号节点不使用

	//清空
	for (int i = 1; i <= m; ++i) {
		hT[i].parent = hT[i].lChild = hT[i].rChild = 0;
	}

	cout << "请输入各个点对应的权值：" << endl;
	for (int i = 1; i <= n; ++i) {
		cin >> hT[i].weight;    // 输入权值
	}
	hT[0].weight = m;    // 用0号节点保存节点数量

	for (int i = n + 1; i <= m; ++i) {
		int s1, s2;
		SelectMin(hT, i, s1, s2);

		hT[s1].parent = hT[s2].parent = i;
		hT[i].lChild = s1; hT[i].rChild = s2;    // 作为新节点的孩子
		hT[i].weight = hT[s1].weight + hT[s2].weight;    // 新节点为左右孩子节点权值之和
	}
}

void CreateHuffmanCode(HuffmanTree hT, HuffmanCode& hC)//构造根据哈夫曼树来哈夫曼编码
{
	hC.n = (hT[0].weight + 1) / 2;
	hC.code = new char* [hC.n + 1];    // 0位置不使用

	char* cd = new char[hC.n];  // 临时存放每个编码

	for (int i = 1; i <= hC.n; ++i) {

		// 每次从叶子节点向上回溯构造编码
		int len = 0, child = i, parent = hT[i].parent;
		while (parent != 0) {//直至上溯搭配parent为树根为止
			if (hT[parent].lChild == child) {//若为子孩子，则生成代码0，否则生成1
				cd[len++] = '0';
			}
			else {
				cd[len++] = '1';
			}
			child = parent;
			parent = hT[parent].parent;
		}
		cd[len] = 0;

		reverse(cd, cd + len);//将序列翻转
		hC.code[i] = new char[len];
		strcpy(hC.code[i], cd);//复制编码位串
	}
	delete[] cd;
}

void PrintHuffmanCode(HuffmanCode& hC)//输出哈夫曼表
{
	for (int i = 1; i <= hC.n; ++i) {
		cout << i << ":" << hC.code[i] << endl;
	}
}
