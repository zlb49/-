#include <iostream>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>
using namespace std;
void InsertSort(int* a, int left, int right)//对数组进行排序
{
	for (int i = left + 1; i <= right; i++)
	{
		if (a[i - 1] > a[i])
		{
			int t = a[i];
			int j = i;
			while (j > left&& a[j - 1] > t)
			{
				a[j] = a[j - 1];
				j--;
			}
			a[j] = t;
		}
	}
}
int FindMid(int* num, int left, int right)
{
	if (left == right) return left;
	int i = 0;
	int n = 0;
	for (i = left; i < right - 5; i += 5)//对数组排序并将中位数放到最前面
	{
		InsertSort(num, i, i + 4);
		n = i - left;
		swap(num[left + n / 5], num[i + 2]);
	}

	int w = right - i + 1;
	if (w > 0)//对剩余部分排序并将中位数放到最前面
	{
		InsertSort(num, i, i + w - 1);
		n = i - left;
		swap(num[left + n / 5], num[i + w / 2]);
	}
	n /= 5;
	if (n == left) return left;
	return FindMid(num, left, left + n);
}
int Partion(int* num, int left, int right, int p)
{
	swap(num[p], num[left]);
	int i = left;
	int j = right;
	int pivot = num[left];
	while (i < j)
	{
		while (num[j] >= pivot && i < j) //找到第一个比pivot小的数字的下标j;
		{
			j--;
		}
		num[i] = num[j];
		while (num[i] <= pivot && i < j) //找到第一个比pivot大的数字的下标i;
		{
			i++;
		}
		num[j] = num[i];
	}
	num[i] = pivot;
	return i;
}

int Select(int* num, int left, int right, int k)
{
	int p = FindMid(num, left, right);
	int i = Partion(num, left, right, p);

	int m = i - left + 1;
	if (m == k) 
	{
		return num[i];
	}
	if (m > k) 
	{
		return Select(num, left, i - 1, k);
	}
	return Select(num, i + 1, right, k - m);
}

int main()
{

	int n, k;
	cin >> n;
	int* num = (int*)malloc(sizeof(int) * n);//分配空间
	for (int i = 0; i < n; i++)cin >> num[i];
	cin >> k;
	printf("%d\n",Select(num, 0, n - 1, k));
	return 0;
}

