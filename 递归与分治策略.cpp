#include <iostream>
#include <time.h> 
using namespace std;
//�̲Ļ����������ļ�����㷨������������3�棩

void _New();

void _Assign();

void _Print();

void _Delete();


//��2-1�׳�
int factorial(int n)
{
	if (n == 0)
		return 1;
	return n*factorial(n - 1);

}
//��2-2 Fibonacci����
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
//��2-4 ȫ��������
template<class Type>
void Perm(Type list[], int k, int m)
{	//����list[k:m]������ȫ����
	if (k == m)
	{//ֻʣһ��Ԫ��
		for (int i = 0; i <= m; i++)
			cout << list[i]<<" ";
		cout << endl;
	}
	else//���ж��Ԫ�ش����У��ݹ��������
		for (int i = k; i <= m; i++)//ѭ��������һ��Ԫ������������Ԫ��ʵ��ȫ//����
		{
			Swap(list[k], list[i]);
			Perm(list, k + 1, m);
			Swap(list[k], list[i]);
		}
}
//�� 2-5 ������������
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
//�� 2-6��ŵ������
void hanoi(int n, char a, char b, char c)
{
	if (n > 0)
	{
		hanoi(n - 1, a, c , b);
		move(a, b);
		hanoi(n - 1, c, b, a);
	}
}

//���η�
//2.3 ���ֲ���
template<class Type>int BinarySearch(Type a[], const Type& x, int l, int r){	while(r >= l)	{		int m = (l + r) / 2;		if (x == a[m]) 			return m;		if (x < a[m]) 			r = m - 1; 		else l = m + 1;	}	return -1;}

//2.8��������
template<class Type>int Partition(Type a[],int p,int r){	int i = p,j = r + 1;	Type x = a[p];	while (true) 	{		while (a[++i] < x);		while (a[--j] > x);		if (i >= j) 			break;		Swap(a[i], a[j]);	}	a[p] = a[j];	a[j] = x;	return j;}template <class Type>void QuickSort(Type a[], int p, int r){
	if (p<r) {		int q = Partition(a, p, r);		QuickSort(a, p, q - 1);		QuickSort(a, q + 1, r);
	}
}

int Random(int a, int b)
{
	if (a< b)
	{
		int temp = a;
		a = b;
		b = temp;

	}
	int c = a - b;

	int d=rand() *c;

	int e=b + d;
	cout <<"a="<< a <<",b="<< b<<",d=" << d <<",e="<< e << endl;
	return e;

}
//������������򻮷�
template<class Type>int RandomizedPartition(Type a[], int p, int r){	int i = Random(p, r);	Swap(a[i], a[p]);	return Partition(a, p, r);}

//�������������
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

#define arrLen(x) sizeof(x)/sizeof(x[0])

//��2�� �ݹ�����β���
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
	cout << "��ŵ����������Բ����" << n <<endl;
	hanoi(n, 'A', 'B', 'C');
	
	int list_bsearch[] = { 2,12,34,45,52,59 };

	int r=BinarySearch(list_bsearch, 59, 0, arrLen(list_bsearch));
	cout << r << endl;

	int list_qsort[] = { 32,2,4,45,52,9 };
	QuickSort(list_qsort, 0, arrLen(list_qsort) - 1);
	_Print(list_qsort, arrLen(list_qsort));

	int list_qsort2[]= { 32,2,4,45,52,9 };
	//RandomizedQuickSort(list_qsort2, 0, arrLen(list_qsort2) - 1);
	_Print(list_qsort2, arrLen(list_qsort2));



	return 0;
}