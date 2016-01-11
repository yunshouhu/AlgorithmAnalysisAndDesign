#include <iostream>
using namespace std;

void _New();

void _Assign();

void _Print();

void _Delete();


//2.1阶乘
int factorial(int n)
{
	if (n == 0)
		return 1;
	return n*factorial(n - 1);

}
//2.2 Fibonacci数列
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
//2.4 全排列问题
template<class Type>
void Perm(Type list[], int k, int m)
{	//产生list[k:m]的所有全排列
	if (k == m)
	{//只剩一个元素
		for (int i = 0; i <= m; i++)
			cout << list[i];
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

//第2章 递归与分治策略
int main(int argc, char * argv)
{
	cout << factorial(5) << endl;
	int a = fibonacci(6);
	cout << a <<endl;
	int list[] = { 1,2,3,4 };
	Perm(list, 3, 3);
	return 0;
}