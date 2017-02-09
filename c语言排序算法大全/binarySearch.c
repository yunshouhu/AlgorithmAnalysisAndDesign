#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int binarySearch(int a[], int n, int key){
	int low = 0;
	int high = n - 1;
	while (low <= high){
		int mid = (low + high) / 2;
		int midVal = a[mid];
		if (midVal<key)
			low = mid + 1;
		else if (midVal>key)
			high = mid - 1;
		else
			return mid;
	}
	return -1;
}

//�����۰���� http://c.biancheng.net/cpp/html/2744.html
int main(){
	int i, val, ret;
	int a[8] = { -32, 12, 16, 24, 36, 45, 59, 98 };
	for (i = 0; i<8; i++)
		printf("%d\t", a[i]);

	printf("\n��������Ҫ���ҵ�Ԫ�أ�");
	scanf("%d", &val);

	ret = binarySearch(a, 8, val);

	if (-1 == ret)
		printf("����ʧ�� \n");
	else
		printf("���ҳɹ� \n");

	return 0;
}