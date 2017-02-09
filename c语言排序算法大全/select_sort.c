#include <stdio.h>
#include <stdlib.h>
#define arrLen(arr) sizeof(arr)/sizeof(arr[0])

//注意：选择排序是一种不稳定的排序算法，可能会打乱两个相同数字的原有顺序。
void select_sort(int a[], int n)
{
	//进行N-1轮选择
	for (int i = 0; i < n - 1; i++)
	{
		int min_index = i;
		//找出第i小的数所在的位置
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min_index])
			{
				min_index = j;
			}
		}
		//将第i小的数，放在第i个位置；如果刚好，就不用交换
		if (i != min_index)
		{
			int temp = a[i];
			a[i] = a[min_index];
			a[min_index] = temp;
		}
	}
}
//http://c.biancheng.net/cpp/html/2442.html
int main(void){
	int i;
	int arr[] = { 32, 12, 7, 78, 23, 45, 3 };
	int N = arrLen(arr);

	printf("排序前 \n");
	for (i = 0; i<N; i++)
		printf("%d\t", arr[i]);
	select_sort(arr, N);

	printf("\n排序后 \n");
	for (i = 0; i<N; i++)
		printf("%d\t", arr[i]);
	printf("\n");

	system("pause");
	return 0;
}