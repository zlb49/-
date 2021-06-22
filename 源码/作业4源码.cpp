#include<stdio.h>
#include<stdlib.h>

const int n = 8;
int A[n] = { 8,7,6,5,4,3,2,1 };
int B[n];//��ʱ������ݵ�����
void Merge(int A[],int low, int mid, int high)
{
	int x=low, y=low, z=mid+1;
	while (x<=mid&&z<=high)//��A�����������ߵ����ݽ��бȽϣ��������з����ݴ�����B��
	{
		if (A[x] < A[z])B[y++] = A[x++];
		else B[y++] = A[z++];
	}
	while (x <= mid)//Ϊ�´ι鲢��Ԥ����
	{
		B[y++] = A[x++];
	}
	while (z<=high)//Ϊ�´ι鲢��Ԥ����
	{
		B[y++] = A[z++];
	}
	for (y = low; y <= high; y++)//�Ƚ���ϣ�����ʱ��ŵ�������Ϊ�鲢�����Ż�A
	{
		A[y] = B[y];
	}
}

void MergeSort(int A[],int low,int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(A,low, mid);//��������
		MergeSort(A,mid + 1, high);//�����Ұ��
		Merge(A,low, mid, high);// �����ߺ��Ұ�߽�������鲢
	}
}


int main() 
{	
	MergeSort(A,0,n-1);
	for (int i = 0; i < n; i++) 
	{
		printf("%d ",A[i]);
	}
}
