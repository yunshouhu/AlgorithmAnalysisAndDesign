#include <iostream>
using namespace std;

void _New();

void _Assign();

void _Print();

void _Delete();


//2.1�׳�
int factorial(int n)
{
	if (n == 0)
		return 1;
	return n*factorial(n - 1);

}
//2.2 Fibonacci����
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
//2.4 ȫ��������
template<class Type>
void Perm(Type list[], int k, int m)
{	//����list[k:m]������ȫ����
	if (k == m)
	{//ֻʣһ��Ԫ��
		for (int i = 0; i <= m; i++)
			cout << list[i];
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

//��2�� �ݹ�����β���
int main(int argc, char * argv)
{
	cout << factorial(5) << endl;
	int a = fibonacci(6);
	cout << a <<endl;
	int list[] = { 1,2,3,4 };
	Perm(list, 3, 3);
	return 0;
}