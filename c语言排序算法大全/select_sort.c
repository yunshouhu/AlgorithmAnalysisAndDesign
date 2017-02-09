#include <stdio.h>
#include <stdlib.h>
#define arrLen(arr) sizeof(arr)/sizeof(arr[0])

//ע�⣺ѡ��������һ�ֲ��ȶ��������㷨�����ܻ����������ͬ���ֵ�ԭ��˳��
void select_sort(int a[], int n)
{
	//����N-1��ѡ��
	for (int i = 0; i < n - 1; i++)
	{
		int min_index = i;
		//�ҳ���iС�������ڵ�λ��
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min_index])
			{
				min_index = j;
			}
		}
		//����iС���������ڵ�i��λ�ã�����պã��Ͳ��ý���
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

	printf("����ǰ \n");
	for (i = 0; i<N; i++)
		printf("%d\t", arr[i]);
	select_sort(arr, N);

	printf("\n����� \n");
	for (i = 0; i<N; i++)
		printf("%d\t", arr[i]);
	printf("\n");

	system("pause");
	return 0;
}