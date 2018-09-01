
#include <stdio.h>
#include <stdlib.h>
#define arrLen(arr) sizeof(arr)/sizeof(arr[0])

void print(int arr[], int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

}

int partition(int arr[], int low, int high){
	int key;
	key = arr[low];
	while (low < high){
		while (low < high && arr[high] >= key)
			high--;
		if (low < high)
			arr[low++] = arr[high];
		while (low < high && arr[low] <= key)
			low++;
		if (low < high)
			arr[high--] = arr[low];
	}
	arr[low] = key;

	return low;
}
//快速排序
void quick_sort(int arr[], int start, int end){
	int pos;
	if (start < end){
		pos = partition(arr, start, end);
		quick_sort(arr, start, pos - 1);
		quick_sort(arr, pos + 1, end);
	}
	return;
}
//冒泡排序
void bubble_sort(int arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int isSorted = 1;
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j]> arr[j + 1])
			{
				isSorted = 0;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		//如果没有发生交换，说明数组已经排序好了
		if (isSorted)
		{
			break;
		}
	}
}
//插入排序
void insert_sort(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int j = 0;
		while (arr[j] < arr[i] && j < i)
		{
			j++;
		}
		if (i != j)
		{
			int tmp = arr[i];
			for (int k = i; k>j; k--)
			{
				arr[k] = arr[k - 1];
			}
			arr[j] = tmp;
		}
	}
}
void merge(int arr[], int low, int mid, int high)
{
	int i, k;
	int *tmp = (int*)malloc(sizeof(int)* (high - low + 1));
	int left_low = low;
	int left_high = mid;
	int right_low = mid + 1;
	int right_high = high;
	for (k = 0; left_low <= left_high && right_low <= right_high; k++)
	{
		if (arr[left_low] <= arr[right_low])
		{
			tmp[k] = arr[left_low++];
		}
		else{
			tmp[k] = arr[right_low++];
		}
	}
	if (left_low <=left_high)
	{
		for (i = left_low; i <= left_high; i++)
		{
			tmp[k++] = arr[i];
		}
	}
	if (right_low <= right_high)
	{
		for (i = right_low; i <= right_high; i++)
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
//归并排序
void merge_sort(int arr[], int left, int right)
{
	int bp = 9;
	int mid = 0;
	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid+1, right);
		merge(arr, left, mid, right);
		int bp = 9;
	}
	return ;

}
//选择排序
void select_sort(int arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int mid_index = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[mid_index])
			{
				mid_index = j;
			}
		}
		if (i != mid_index)
		{
			int temp = arr[i];
			arr[i] = arr[mid_index];
			arr[mid_index] = temp;
		}

	}
}
//希尔排序
void shell_sort(int arr[], int len)
{
	for (int step = len / 2; step > 0; step = step / 2)
	{
		for (int i = step; i < len; i++)
		{
			for (int j = i - step; j >= 0 && arr[j]> arr[j + step]; j = j - step)
			{
				int temp = arr[j];
				arr[j] = arr[j + step];
				arr[j + step] = temp;
			}
		}
	}
}

int binarySearch(int arr[], int n, int key)
{
	int low = 0;
	int high = n - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int mid_value = arr[mid];
		if (mid_value < key)
		{
			low = mid + 1;
		}
		else if (mid_value>key)
		{
			high = mid - 1;
		}
		else{
			return mid;
		}
	}
	return -1;
}

//c语言实现常用排序算法

//http://c.biancheng.net/cpp/html/2741.html
int main(void){
	{

		int arr[] = { 32, 12, 7, 78, 23, 45, 3, 6, 9 };
		int len = arrLen(arr);
		printf("==========quick_sort============\n");
		print(arr, len);
		quick_sort(arr, 0, len - 1);
		print(arr, len);
	}
	{
		int arr[] = { 32, 12, 7, 78, 23, 45, 3, 6, 9 };
		int len = arrLen(arr);
		printf("==========bubble_sort============\n");
		print(arr, len);
		bubble_sort(arr, len);
		print(arr, len);
	}
	{
		int arr[] = { 32, 12, 7, 78, 23, 45, 3, 6, 9 };
		int len = arrLen(arr);
		printf("==========insert_sort============\n");
		print(arr, len);
		insert_sort(arr, len);
		print(arr, len);
	}
	{
		int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
		int len = arrLen(arr);
		printf("==========merge_sort============\n");
		print(arr, len);
		merge_sort(arr,0, len-1);
		print(arr, len);
	}
	{
		int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
		int len = arrLen(arr);
		printf("==========select_sort============\n");
		print(arr, len);
		select_sort(arr, len);
		print(arr, len);
	}

	{
		int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
		int len = arrLen(arr);
		printf("==========shell_sort============\n");
		print(arr, len);
		shell_sort(arr, len);
		print(arr, len);
	}


	return 0;
}
