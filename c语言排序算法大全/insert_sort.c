#include <stdio.h>
#include <stdlib.h>
#define arrLen(arr) sizeof(arr)/sizeof(arr[0])

void insert_sort(int a[], int n)
{
	//����N-1�ֲ������
	for (int i = 0; i < n ; i++)
	{
		//�����ҵ�Ԫ��a[i]��Ҫ�����λ��
		int j = 0;
		while ((a[j] < a[i]) && j < i)//a[j] > a[i]����
		{
			j++;
		}
		//���i==j��˵��a[i]�պ�����ȷ��λ��
		if (i != j)
		{
			int temp = a[i];
			//�ƶ�Ԫ��
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

	printf("����ǰ \n");
	for (i = 0; i<N; i++)
		printf("%d\t", arr[i]);
	insert_sort(arr, N);

	printf("\n����� \n");
	for (i = 0; i<N; i++)
		printf("%d\t", arr[i]);
	printf("\n");

	system("pause");
	return 0;
}