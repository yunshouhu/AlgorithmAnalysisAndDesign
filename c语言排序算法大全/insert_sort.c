#include <stdio.h>
#include <stdlib.h>
#define arrLen(arr) sizeof(arr)/sizeof(arr[0])

void insert_sort(int a[], int n)
{
	//进行N-1轮插入过程
	for (int i = 0; i < n ; i++)
	{
		//首先找到元素a[i]需要插入的位置
		int j = 0;
		while ((a[j] < a[i]) && j < i)//a[j] > a[i]升序。
		{
			j++;
		}
		//如果i==j，说明a[i]刚好在正确的位置
		if (i != j)
		{
			int temp = a[i];
			//移动元素
			for (int k = i; k>j; k--)
			{
				a[k] = a[k - 1];
			}
			a[j] = temp;
		}
	}
}

//http://c.biancheng.net/cpp/html/2492.html
int main(void){
	int i;
	int arr[] = { 32, 12, 7, 78, 23, 12, 45, 3 };
	int N = arrLen(arr);

	printf("排序前 \n");
	for (i = 0; i<N; i++)
		printf("%d\t", arr[i]);
	insert_sort(arr, N);

	printf("\n排序后 \n");
	for (i = 0; i<N; i++)
		printf("%d\t", arr[i]);
	printf("\n");

	system("pause");
	return 0;
}