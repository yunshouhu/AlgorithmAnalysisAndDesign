
#include <stdio.h>
#include <stdlib.h>
#define arrLen(arr) sizeof(arr)/sizeof(arr[0])


int partition(int arr[], int low, int high){
	int key;
	key = arr[low];
	while (low<high){
		while (low <high && arr[high] >= key)
			high--;
		if (low<high)
			arr[low++] = arr[high];
		while (low<high && arr[low] <= key)
			low++;
		if (low<high)
			arr[high--] = arr[low];
	}
	arr[low] = key;

	return low;
}

void quick_sort(int arr[], int start, int end){
	int pos;
	if (start<end){
		pos = partition(arr, start, end);
		quick_sort(arr, start, pos - 1);
		quick_sort(arr, pos + 1, end);
	}
	return;
}

//http://c.biancheng.net/cpp/html/2741.html
int main(void){
	int i;
	int arr[] = { 32, 12, 7, 78, 23, 45,3 };
	int N = arrLen(arr);

	printf("ÅÅÐòÇ° \n");
	for (i = 0; i<N; i++)
		printf("%d\t", arr[i]);
	quick_sort(arr, 0, N - 1);

	printf("\nÅÅÐòºó \n");
	for (i = 0; i<N; i++)
		printf("%d\t", arr[i]);
	printf("\n");

	system("pause");
	return 0;
}
