#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ordersearch(int a[], int n, int des){
	int i;
	for (i = 0; i<n; i++)
	if (des == a[i])
		return 1;

	return 0;
}

int main(){
	int i, val;
	int a[8] = { 32, 12, 56, 78, 76, 45, 43, 98 };
	int ret;

	for (i = 0; i<8; i++)
		printf("%d\t", a[i]);

	printf("\n��������Ҫ���ҵ�Ԫ�أ�");
	while (1){
		scanf("%d", &val);
		ret = ordersearch(a, 8, val);

		if (1 == ret)
			printf("���ҳɹ���");
		else
			printf("����ʧ�ܣ�");

		printf("\n��������Ҫ���ҵ�Ԫ�أ�");
	}

	return 0;
}