#include <stdio.h>
#include <stdlib.h>
#define arrLen(arr) sizeof(arr)/sizeof(arr[0])

void merge_my(int arr[], int low, int mid, int high)
{
	int i, k;
	int* tmp = (int*)malloc((high - low + 1)*sizeof(int));

	int left_low = low;
	int left_high = mid;
	int right_low = mid + 1;
	int right_high = high;
	for (k = 0; left_low <= left_high && right_low <= right_high; k++)
	{
		if (arr[left_low] <= arr[right_low])
		{
			tmp[k] = arr[left_low++];
		}else
		{
			tmp[k] = arr[right_low++];
		}
	}
	if (left_low <= left_high)
	{
		for (i = left_low; i <= left_high; i++)
		{
			tmp[k++] = arr[i];
		}
	}
	if (right_low <= right_high)
	{
		for (i = right_low; i <=right_high; i++)
		{
			tmp[k++] = arr[i];
		}
	}
	for (i = 0; i < high - low + 1; i++)
	{
		arr[low + i] = tmp[i];
	}
	free(tmp);
	return;
}

void merge(int arr[], int low, int mid, int high){
	int i, k;
	int *tmp = (int *)malloc((high - low + 1)*sizeof(int));
	//申请空间，使其大小为两个
	int left_low = low;
	int left_high = mid;
	int right_low = mid + 1;
	int right_high = high;
	for (k = 0; left_low <= left_high && right_low <= right_high; k++){  // 比较两个指针所指向的元素
		if (arr[left_low] <= arr[right_low]){
			tmp[k] = arr[left_low++];
		}
		else{
			tmp[k] = arr[right_low++];
		}
	}
	if (left_low <= left_high){  //若第一个序列有剩余，直接复制出来粘到合并序列尾
		//memcpy(tmp+k, arr+left_low, (left_high-left_low+l)*sizeof(int));
		for (i = left_low; i <= left_high; i++)
			tmp[k++] = arr[i];
	}
	if (right_low <= right_high){
		//若第二个序列有剩余，直接复制出来粘到合并序列尾
		//memcpy(tmp+k, arr+right_low, (right_high-right_low+1)*sizeof(int));
		for (i = right_low; i <= right_high; i++)
			tmp[k++] = arr[i];
	}
	for (i = 0; i<high - low + 1; i++)
		arr[low + i] = tmp[i];
	free(tmp);
	return;
}
void merge_sort(int arr[], int left,int right)
{
	int mid = 0;
	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
	return;
	
}

//http://c.biancheng.net/cpp/html/2742.html
int main(void){
	int i;
	int arr[] = { 32, 12, 7, 78, 23, 12, 45, 3 };
	int N = arrLen(arr);

	printf("排序前 \n");
	for (i = 0; i<N; i++)
		printf("%d\t", arr[i]);
	merge_sort(arr,0, N-1);

	printf("\n排序后 \n");
	for (i = 0; i<N; i++)
		printf("%d\t", arr[i]);
	printf("\n");

	system("pause");
	return 0;
}