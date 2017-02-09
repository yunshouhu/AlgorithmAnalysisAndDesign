#include <stdio.h>
#include <stdlib.h>
#define arrLen(arr) sizeof(arr)/sizeof(arr[0])

void bubble_sort(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}	
}
//优化实现
void bubble_sort_better(int a[], int n)
{
	//最多进行N-1轮比较
	for (int i = 0; i < n-1; i++)
	{
		int isSorted = 1;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				isSorted = 0;
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
		//如果没有发生交换，说明数组已经排序好了
		if (isSorted)
			break;
	}
}
//http://c.biancheng.net/cpp/html/2443.html
//冒泡排序，以int[]为例子学习算法思想。
int main(void){
	int i;
	int arr[] = { 32, 12, 7, 78, 23,12, 45, 3 };
	int N = arrLen(arr);

	printf("排序前 \n");
	for (i = 0; i<N; i++)
		printf("%d\t", arr[i]);
	//bubble_sort(arr, N);
	bubble_sort_better(arr, N);

	printf("\n排序后 \n");
	for (i = 0; i<N; i++)
		printf("%d\t", arr[i]);
	printf("\n");

	system("pause");
	return 0;
}