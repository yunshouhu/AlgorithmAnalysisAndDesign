
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
��������
�������
ѡ��һ����ŦԪ������ѡ���ף�β��������������λ����Ϊ��ŦԪ��
����ŦԪ��Ϊֹ�������β��ַ���н�����
��������ָ�룬P1ָ�������׵�ַ��P2ָ�����鵹���ڶ���λ�ã�P1��ָԪ�ص�ֵ����ŦԪ�Ƚϣ����С����ŦԪ�����һλ��������ھ�ͣ������P1��ָԪ�ص�ֵ����ŦԪ�Ƚϣ����������ŦԪ��ǰ��һλ�����С�ھ�ͣ������
����P1��P2��ָ���Ԫ�أ�
�ظ����ͣ�ֱ��P1����P2��
������ķָ����ͬ�����õݹ�ķ�����
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



//ð������
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
		//���û�з���������˵�������Ѿ��������
		if (isSorted)
		{
			break;
		}
	}
}
//��������
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
//�鲢����
//������δ��м�ֳ���������N1��N2,Ȼ��ݹ������鲢��
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
//ѡ������
//1��ÿһ�δӺ���ѡ���һ����С��ֵ��swap_pos�����滻��ǰ����(i)��
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
//ϣ������
//ϣ���������ڲ�������Ļ����Ͻ��з�չ�ģ�ͨ��һ��ϣ������������һ����������ݡ�
//�������Ӷ�:O(N^2) ���ȶ�����
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

//������
//���ѵ�ƽ��ʱ���ǣ�O(N)
//���ѵ������ǣ�O(NlogN)
//ɾ��Ԫ�ص�ʱ���ǣ�O(logN)
//��������ƽ��ʱ�临�Ӷȣ�O(N+NlogN)=O(NlogN)
//�������Ӷȣ�O(NlogN)
//���ȶ�����

//����һ���󶥶�O(n),Ҫ����� ������Ԫ�� �ƶ����Ѷ� Ҳ����a[0]
void make_heap(int a[], int len) //size�ĵ�ǰ�ѵĴ�С��Ҳ���������ǰsize����
{
	for (int i = len - 1; i > 0; i--)
	{
		if (i % 2 && a[i] > a[(i - 1) / 2])//����
			swap(&a[i], &a[(i - 1) / 2]);
		else if (i % 2 == 0 && a[i] > a[(i - 2) / 2])//ż��
			swap(&a[i], &a[(i - 2) / 2]);
	}
}
void heap_sort(int a[],int len)
{
	int n =len;
	while (n)
	{
		make_heap(a, n); //ÿ�ΰ��µ����Ԫ���Ƶ��Ѷ���Ҳ����a[0]
		n--;
		swap(&a[0], &a[n]); //Ȼ��ѵ�ǰ����ƶ�����������Ϊ�ź����Ԫ��
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
//���������ÿһ�ִ�����ʵ���ǽ���һ�ֵĻ�׼����λ��ֱ�����е�������λΪֹ������ͽ����ˡ�
void my_qsort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pos = my_partition(arr, low, high);
		my_qsort(arr, 0, pos-1);
		my_qsort(arr, pos+1, high);
	}
}
//��ʱ�Ի�׼��6Ϊ�ֽ�㣬6��ߵ�����С�ڵ���6��6�ұߵ��������ڵ���6��
//�ع�һ�¸ղŵĹ��̣���ʵ�ڱ�j��ʹ������Ҫ��С�ڻ�׼�����������ڱ�i��ʹ������Ҫ�Ҵ��ڻ�׼��������ֱ��i��j��ͷΪֹ��
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

	base = arr[left]; //temp�д�ľ��ǻ�׼�� 
	i = left;
	j = right;
	while (i != j)
	{
		//˳�����Ҫ��Ҫ�ȴ��ұ߿�ʼ�� 
		while (arr[j] >= base && i < j)
			j--;
		//�����ұߵ� 
		while (arr[i] <= base && i < j)
			i++;
		//�����������������е�λ�� 
		if (i < j)
		{
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}
	//���ս���׼����λ 
	arr[left] = arr[i];
	arr[i] = base;

	quicksort(arr,left, i-1);//����������ߵģ�������һ���ݹ�Ĺ��� 
	quicksort(arr,i + 1, right);//���������ұߵ� ��������һ���ݹ�Ĺ��� 
}



//c����ʵ�ֳ��������㷨

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
