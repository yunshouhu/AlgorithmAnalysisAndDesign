
#include <iostream>
#include <string>
using namespace std;

int * array_list;
int * array_list_a;
void print_list(int *, int);
void count_sort(int *, int *, int,int);

//�������� http://blog.csdn.net/harry_lyc/article/details/7722347
int main(int argc, char * argv[])
{
	int size = 10;
	/**
	array_list = new int[sizeof(int)*size];
	array_list_a = new int[sizeof(int)*size];
	srand(0);
	for (int i = 0; i < size; i++)
	{	//������������Ԫ��
		int ran_num = rand() % size;
		array_list[i] = ran_num;
	}
	*/
	cin >> size;
	array_list = new int[sizeof(int)*size];
	array_list_a = new int[sizeof(int)*size];
	for (int i = 0; i < size; i++)
	{
		cin >> array_list[i];
	}
	print_list(array_list, size);
	count_sort(array_list, array_list_a, size,100);
	print_list(array_list_a, size);
	delete array_list;
	delete array_list_a;
	return 0;
}
/*Ҫ����������ݶ��ǽ���0 - k ����*/
void count_sort(int * array_list_a, int * array_list_b,int size, int k)
{
	int * c = new int[sizeof(int) * k];
	for (int i = 0; i < k; i++)
	{/*��ʼ����ʱ����*/
		c[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{/*��������������ظ�����ֵ����ͳ�ƣ�����ʱ����c����Ӧ��λ�����Լ�¼*/
		c[array_list_a[i]] += 1;
	}
	for (int i = 1; i < k; i++)
	{/*С�ڵ�ǰ����Ԫ�صĸ���*/
		c[i] += c[i - 1];
	}

	for (int j = size - 1; j >= 0; j--)
	{
		array_list_b[c[array_list_a[j]] - 1] = array_list_a[j];
		c[array_list_a[j]] -= 1;
	}
	delete c;
}
void print_list(int * array_list, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << array_list[i] << "\t";
	}
	std::cout << std::endl;
}

