
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <windows.h>
using namespace std;


/*
* ��s�е�sIndexλ�ÿ�ʼƥ��p
* ��ƥ��ɹ�������s��ģʽ��p����ʼindex
* ��ƥ��ʧ�ܣ�����-1
*/
int index(const std::string &s, const std::string &p, const int sIndex = 0)
{
	int i = sIndex, j = 0;

	if (s.length() < 1 || p.length() < 1 || sIndex < 0)
	{
		return -1;
	}

	while (i != s.length() && j != p.length())
	{
		if (s[i] == p[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	return j == p.length() ? i - j : -1;
}

void getNext(const std::string &p, std::vector<int> &next);

int kmp(const std::string& s, const std::string& p, const int sIndex = 0)
{
	std::vector<int>next(p.size());
	getNext(p, next);//��ȡnext���飬���浽vector��

	int i = sIndex, j = 0;
	while (i != s.length() && j != p.length())
	{
		if (j == -1 || s[i] == p[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}

	return j == p.length() ? i - j : -1;
}

void getNext(const std::string &p, std::vector<int> &next)
{
	next.resize(p.size());
	next[0] = -1;

	int i = 0, j = -1;

	while (i != p.size() - 1)
	{
		//����ע�⣬i==0��ʱ��ʵ���������next[1]��ֵ���Դ�����
		if (j == -1 || p[i] == p[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

void getNextUpdate(const std::string& p, std::vector<int>& next)
{
	next.resize(p.size());
	next[0] = -1;

	int i = 0, j = -1;

	while (i != p.size() - 1)
	{
		//����ע�⣬i==0��ʱ��ʵ���������nextVector[1]��ֵ���Դ�����
		if (j == -1 || p[i] == p[j])
		{
			++i;
			++j;
			//update
			//next[i] = j;
			//ע��������++i��++j֮���p[i]��p[j]
			next[i] = p[i] != p[j] ? j : next[j];
		}
		else
		{
			j = next[j];
		}
	}
}
void mysleep()
{
#if defined(_WIN32)  

	Sleep(1000);//1s
#else  
#include <syswait.h>
	sleep(1);//1s
#endif
}
//http://www.cnblogs.com/goagent/archive/2013/05/16/3068442.html
int main()
{
	time_t start, end;
	time(&start);
	cout << index("xxabcxxabcxxxabcxdabctdeefghijkkklmn123456ooabcdefdd", "abcd") << endl;
	mysleep();
	time(&end);
	

	printf("index ����ʱ�� %f��\n", difftime(end, start));

	time(&start);
	cout << kmp("xxabcxxabcxxxabcxdabctdeefghijkkklmn123456ooabcdefdd", "abcd") << endl;

	mysleep();
	time(&end);
	printf("kmp ����ʱ�� %f��\n", difftime(end, start));

	return 0;
}