
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
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


int partition(int arr[],int low,int high)
{
	int key = arr[low];
	while (low < high)
	{
		while (low < high && arr[high] >= key)
		{
			high--;
		}
		if (low < high)
		{
			arr[low++] = arr[high];
		}
		while (low < high && arr[low] <= key)
		{
			low++;
		}
		if (low < high)
		{
			arr[high--] = arr[low];
		}
	}
	arr[low] = key;
	return low;
}
/**
快速排序
排序过程
选择一个枢纽元，可以选择首，尾，中三个数的中位数作为枢纽元；
将枢纽元的为止与数组的尾地址进行交换；
定义两个指针，P1指向数组首地址，P2指向数组倒数第二个位置，P1所指元素的值与枢纽元比较，如果小于枢纽元则后移一位，如果大于就停下来。P1所指元素的值与枢纽元比较，如果大于枢纽元则前移一位，如果小于就停下来；
交换P1和P2所指向的元素；
重复３和４直到P1大于P2；
对数组的分割过程同样采用递归的方法。
*/
void quick_sort(int arr[], int start,int end)
{
	int bp = 1;
	int pos;
	if (start < end)
	{
		pos = partition(arr, start, end);
		quick_sort(arr, start, pos-1);
		quick_sort(arr, pos+1, end);
		int bp = 1;
	}
	return;
}


//https://blog.csdn.net/liqinzhe11/article/details/78743743
int findmiddle(int a, int b, int c)
{
	if (a >= b && a <= c)
		return a;
	else if (b >= a && b <= c)
		return b;
	else
		return c;
}
void quicksortHelper(int a[], int start, int end)
{
	if (start >= end) 
		return;
	int l = start;
	int r = end;
	int pivot = findmiddle(a[start], a[end], a[(end - start) / 2 + start]);
	while (l <= r)
	{
		while (l <= r && a[r] > pivot) 
			r--;
		while (l <= r && a[l] < pivot) 
			l++;
		if (l <= r) 
			swap(&a[l++], &a[r--]);
	}
	quicksortHelper(a, start, r);
	quicksortHelper(a, l, end);
}
void quick_sort2(int a[],int len)
{
	quicksortHelper(a, 0,len - 1);
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
		int tmp = arr[i];
		while (arr[j] < arr[i] && j < i)
		{
			j++;
		}
		if (i != j)
		{		
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
//将数组Ｎ从中间分成两个数组N1和N2,然后递归两两归并。
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
//1、每一次从后面选择出一个最小的值（swap_pos），替换到前面来(i)。
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
//希尔排序是在插入排序的基础上进行发展的，通过一个希尔增量先排序一定间隔的数据。
//最坏情况复杂度:O(N^2) 不稳定排序
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

//堆排序
//建堆的平均时间是：O(N)
//建堆的最坏情况是：O(NlogN)
//删除元素的时间是：O(logN)
//整个排序平均时间复杂度：O(N+NlogN)=O(NlogN)
//最坏情况复杂度：O(NlogN)
//不稳定排序

//建立一个大顶堆O(n),要求就是 把最大的元素 移动到堆顶 也就是a[0]
void make_heap(int a[], int len) //size的当前堆的大小，也就是数组的前size个数
{
	for (int i = len - 1; i > 0; i--)
	{
		if (i % 2 && a[i] > a[(i - 1) / 2])//奇数
			swap(&a[i], &a[(i - 1) / 2]);
		else if (i % 2 == 0 && a[i] > a[(i - 2) / 2])//偶数
			swap(&a[i], &a[(i - 2) / 2]);
	}
}
void heap_sort(int a[],int len)
{
	int n =len;
	while (n)
	{
		make_heap(a, n); //每次把新的最大元素移到堆顶，也就是a[0]
		n--;
		swap(&a[0], &a[n]); //然后把当前最大移动到后面来作为排好序的元素
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

int my_partition(int arr[], int low, int high)
{
	int key = arr[low];
	while (low < high)
	{
		while (low<high && arr[high] >= key)
		{
			high--;
		}
		if(low<high)
			arr[low++] = arr[high];

		while (low < high && arr[high] <= key)
		{
			low++;
		}
		if(low<high)
			arr[high--] = arr[low];
	}
	arr[low] = key;
	return low;
}
//快速排序的每一轮处理其实就是将这一轮的基准数归位，直到所有的数都归位为止，排序就结束了。
void my_qsort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pos = my_partition(arr, low, high);
		my_qsort(arr, 0, pos-1);
		my_qsort(arr, pos+1, high);
	}
}
//此时以基准数6为分界点，6左边的数都小于等于6，6右边的数都大于等于6。
//回顾一下刚才的过程，其实哨兵j的使命就是要找小于基准数的数，而哨兵i的使命就是要找大于基准数的数，直到i和j碰头为止。
void my_sort(int arr[], int left, int right)
{
	if (left >=right)
	{
		return;
	}
	int low = left;
	int high = right;
	int key = arr[low];
	while (low < high)
	{
		while (low < high && arr[high] >= key)
		{
			high--;
		}
		arr[low] = arr[high];
		while (low < high && arr[low] <= key)
		{
			low++;
		}
		arr[high] = arr[low];

	}
	arr[low] = key;
	my_sort(arr, left, low - 1);
	my_sort(arr, low + 1, right);
}
//http://developer.51cto.com/art/201403/430986.htm
void quicksort(int arr[],int left, int right)
{
	int i, j, t, base;
	if (left > right)
		return;

	base = arr[left]; //temp中存的就是基准数 
	i = left;
	j = right;
	while (i != j)
	{
		//顺序很重要，要先从右边开始找 
		while (arr[j] >= base && i < j)
			j--;
		//再找右边的 
		while (arr[i] <= base && i < j)
			i++;
		//交换两个数在数组中的位置 
		if (i < j)
		{
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}
	//最终将基准数归位 
	arr[left] = arr[i];
	arr[i] = base;

	quicksort(arr,left, i-1);//继续处理左边的，这里是一个递归的过程 
	quicksort(arr,i + 1, right);//继续处理右边的 ，这里是一个递归的过程 
}



//c语言实现常用排序算法

//http://c.biancheng.net/cpp/html/2741.html
int main(void){
	{

		//int arr[] = { 32, 12, 7, 78, 23, 45, 3, 6, 9 };
		int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
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
		//int arr[] = { 32, 12, 7, 78, 23, 45, 3, 6, 9 };
		int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
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
	{
		int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
		int len = arrLen(arr);
		printf("==========heap_sort============\n");
		print(arr, len);
		heap_sort(arr, len);
		print(arr, len);
	}
	{
		int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
		int len = arrLen(arr);
		printf("==========quick_sort2============\n");
		print(arr, len);
		quick_sort2(arr, len);
		print(arr, len);
	}
	{
		int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
		int len = arrLen(arr);
		printf("==========my_qsort============\n");
		print(arr, len);
		my_qsort(arr, 0,len-1);
		print(arr, len);
	}
	{
		int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
		int len = arrLen(arr);
		printf("==========my_sort============\n");
		print(arr, len);
		my_sort(arr, 0, len - 1);
		print(arr, len);
	}
	{
		int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
		int len = arrLen(arr);
		printf("==========quicksort============\n");
		print(arr, len);
		quicksort(arr, 0, len - 1);
		print(arr, len);
	}
	

	return 0;
}
