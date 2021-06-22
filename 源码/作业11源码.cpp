#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct//�ڵ�����
{
	int weight;//����Ȩֵ
	int parent, lChild, rChild;//˫��ָ�뼰���Һ���
}HTNode, * HuffmanTree;

typedef struct
{
	char** code;//��ű���λ�������code��Ϊ����
	int n;//������
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
void SelectMin(HuffmanTree hT, int n, int& s1, int& s2)//��ǰk�������ѡ��Ȩֵ��С�ʹ�С�ĸ���㣬����ŷֱ�Ϊs1��s2
{
	s1 = s2 = 0;
	int i;
	for (i = 1; i < n; ++i) {//Ѱ����С�ʹ�С���ڵ�Ĺ���
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

	for (i += 1; i < n; ++i) {//��weight����Ȩֵ��С��������
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

void CreateHufmanTree(HuffmanTree& hT)//������n��Ȩֵ��Ҷ�ӽڵ㣩�Ĺ�������
{
	int n, m;
	cout << "������һ���м����㣺";
	cin >> n;
	m = 2 * n - 1;//�ܽڵ���

	hT = new HTNode[m + 1];    // 0�Žڵ㲻ʹ��

	//���
	for (int i = 1; i <= m; ++i) {
		hT[i].parent = hT[i].lChild = hT[i].rChild = 0;
	}

	cout << "������������Ӧ��Ȩֵ��" << endl;
	for (int i = 1; i <= n; ++i) {
		cin >> hT[i].weight;    // ����Ȩֵ
	}
	hT[0].weight = m;    // ��0�Žڵ㱣��ڵ�����

	for (int i = n + 1; i <= m; ++i) {
		int s1, s2;
		SelectMin(hT, i, s1, s2);

		hT[s1].parent = hT[s2].parent = i;
		hT[i].lChild = s1; hT[i].rChild = s2;    // ��Ϊ�½ڵ�ĺ���
		hT[i].weight = hT[s1].weight + hT[s2].weight;    // �½ڵ�Ϊ���Һ��ӽڵ�Ȩֵ֮��
	}
}

void CreateHuffmanCode(HuffmanTree hT, HuffmanCode& hC)//������ݹ�������������������
{
	hC.n = (hT[0].weight + 1) / 2;
	hC.code = new char* [hC.n + 1];    // 0λ�ò�ʹ��

	char* cd = new char[hC.n];  // ��ʱ���ÿ������

	for (int i = 1; i <= hC.n; ++i) {

		// ÿ�δ�Ҷ�ӽڵ����ϻ��ݹ������
		int len = 0, child = i, parent = hT[i].parent;
		while (parent != 0) {//ֱ�����ݴ���parentΪ����Ϊֹ
			if (hT[parent].lChild == child) {//��Ϊ�Ӻ��ӣ������ɴ���0����������1
				cd[len++] = '0';
			}
			else {
				cd[len++] = '1';
			}
			child = parent;
			parent = hT[parent].parent;
		}
		cd[len] = 0;

		reverse(cd, cd + len);//�����з�ת
		hC.code[i] = new char[len];
		strcpy(hC.code[i], cd);//���Ʊ���λ��
	}
	delete[] cd;
}

void PrintHuffmanCode(HuffmanCode& hC)//�����������
{
	for (int i = 1; i <= hC.n; ++i) {
		cout << i << ":" << hC.code[i] << endl;
	}
}
