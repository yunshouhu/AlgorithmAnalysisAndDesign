
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <windows.h>
using namespace std;


/*
* 从s中第sIndex位置开始匹配p
* 若匹配成功，返回s中模式串p的起始index
* 若匹配失败，返回-1
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
	getNext(p, next);//获取next数组，保存到vector中

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
		//这里注意，i==0的时候实际上求的是next[1]的值，以此类推
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
		//这里注意，i==0的时候实际上求的是nextVector[1]的值，以此类推
		if (j == -1 || p[i] == p[j])
		{
			++i;
			++j;
			//update
			//next[i] = j;
			//注意这里是++i和++j之后的p[i]、p[j]
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
	

	printf("index 花费时间 %f秒\n", difftime(end, start));

	time(&start);
	cout << kmp("xxabcxxabcxxxabcxdabctdeefghijkkklmn123456ooabcdefdd", "abcd") << endl;

	mysleep();
	time(&end);
	printf("kmp 花费时间 %f秒\n", difftime(end, start));

	return 0;
}