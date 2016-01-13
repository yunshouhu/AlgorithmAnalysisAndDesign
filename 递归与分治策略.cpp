#include <iostream>
#include <time.h> 
using namespace std;
//教材基于王晓东的计算机算法设计与分析（第3版）

void _New();

void _Assign();

void _Print();

void _Delete();


//例2-1阶乘
int factorial(int n)
{
	if (n == 0)
		return 1;
	return n*factorial(n - 1);

}
//例2-2 Fibonacci数列
int fibonacci(int n)
{
	if (n <= 1)
		return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}
template<class Type>
inline void Swap(Type &a,Type &b)
{

	Type temp = a;
	a = b;
	b = temp;
}
//例2-4 全排列问题
template<class Type>
void Perm(Type list[], int k, int m)
{	//产生list[k:m]的所有全排列
	if (k == m)
	{//只剩一个元素
		for (int i = 0; i <= m; i++)
			cout << list[i]<<" ";
		cout << endl;
	}
	else//还有多个元素待排列，递归产生排列
		for (int i = k; i <= m; i++)//循环交换第一个元素与其后的所有元素实现全//排列
		{
			Swap(list[k], list[i]);
			Perm(list, k + 1, m);
			Swap(list[k], list[i]);
		}
}
//例 2-5 整数划分问题
int q(int n,int m)
{
	if (n < 1 || m < 1)
		return 0;
	if (n == 1 || m == 1)
		return 1;
	if (n<m)
		return q(n, n);
	if (m == n)
		return q(n, m - 1) + 1;
	return q(n, m - 1) + q(n - m, m);
}

void move(char a, char b)
{
	printf("Move disk  from %c to %c \n",a,b);
}
//例 2-6汉诺塔问题
void hanoi(int n, char a, char b, char c)
{
	if (n > 0)
	{
		hanoi(n - 1, a, c , b);
		move(a, b);
		hanoi(n - 1, c, b, a);
	}
}

//分治法
//2.3 二分查找
template<class Type>int BinarySearch(Type a[], const Type& x, int l, int r){	while(r >= l)	{		int m = (l + r) / 2;		if (x == a[m]) 			return m;		if (x < a[m]) 			r = m - 1; 		else l = m + 1;	}	return -1;}

//2.8快速排序
template<class Type>int Partition(Type a[],int p,int r){	int i = p,j = r + 1;	Type x = a[p];	while (true) 	{		while (a[++i] < x);		while (a[--j] > x);		if (i >= j) 			break;		Swap(a[i], a[j]);	}	a[p] = a[j];	a[j] = x;	return j;}template <class Type>void QuickSort(Type a[], int p, int r){
	if (p<r) {		int q = Partition(a, p, r);		QuickSort(a, p, q - 1);		QuickSort(a, q + 1, r);
	}
}

/**
5.产生一定范围随机数的通用表示公式
要取得[a,b)的随机整数，使用(rand() % (b-a))+ a;
要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a;
要取得(a,b]的随机整数，使用(rand() % (b-a))+ a + 1;
通用公式:a + rand() % n；其中的a是起始值，n是整数的范围。
要取得a到b之间的随机整数，另一种表示：a + (int)b * rand() / (RAND_MAX + 1)。
要取得0～1之间的浮点数，可以使用rand() / double(RAND_MAX)。
*/
int Random(int a, int b)
{
	int c = (rand() % (b - a)) + a;
	//printf("c=%d,a=%d,b=%d\n", c, a, b);
	return c;

}
//随机化快速排序划分
template<class Type>int RandomizedPartition(Type a[], int p, int r){	int i = Random(p, r);	Swap(a[i], a[p]);	return Partition(a, p, r);}

//随机化快速排序
template <class Type>void RandomizedQuickSort(Type a[], int p, int r){
	if (p < r) {		int q = RandomizedPartition(a, p, r);		RandomizedQuickSort(a, p, q - 1);		RandomizedQuickSort(a, q + 1, r);
	}
}

void _Print(int list[],int len)
{
	for (int i = 0; i <len; i++)
	{
		cout << list[i]<<" ";
	}
	cout << endl;

}
//线性时间选择
/*
元素选择问题: 给定线性序集中n个元素和一个整数k，1≤k≤n，要求找出这n个元素中第k小的元素
*/
template<class Type>
Type RandomizedSelect(Type a[], int p, int r, int k)
{
	if (p == r) 
		return a[p];
	int i = RandomizedPartition(a, p, r),
		j = i - p + 1;
	if (k <= j) return RandomizedSelect(a, p, i, k);
	else return RandomizedSelect(a, i + 1, r, k - j);
}



#define arrLen(x) sizeof(x)/sizeof(x[0])

//第2章 递归与分治策略
int main(int argc, char * argv)
{
	cout << factorial(5) << endl;
	int a = fibonacci(6);
	cout << a <<endl;
	int list[] = { 1,2,3,4,5};
	Perm(list, 0, arrLen(list)-1);

	cout << q(6, 6) << endl;
	cout << q(6, 3) << endl;

	int n = 3;
	cout << "汉诺塔问题塔的圆盘数" << n <<endl;
	hanoi(n, 'A', 'B', 'C');
	
	int list_bsearch[] = { 2,12,34,45,52,59 };

	int r=BinarySearch(list_bsearch, 59, 0, arrLen(list_bsearch));
	cout << r << endl;

	int list_qsort[] = { 32,2,4,45,52,9 };
	QuickSort(list_qsort, 0, arrLen(list_qsort) - 1);
	_Print(list_qsort, arrLen(list_qsort));

	int list_qsort2[]= { 32,2,4,45,52,9,69,123,44};
	RandomizedQuickSort(list_qsort2, 0, arrLen(list_qsort2) - 1);
	_Print(list_qsort2, arrLen(list_qsort2));


	int d=RandomizedSelect(list_qsort2, 0, arrLen(list_qsort2) - 1, 5);
	cout << d << endl;

	return 0;
}