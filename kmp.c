#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>

char s[51], t[11];
int next[11];
void get_nextval(char* t, int next[])
{
	int i = 1;
	int j = 0;
	next[0] = -1;
	while (i < strlen(t))
	{
		if (j == -1 || t[i] == t[j])
		{
			i++;
			j++;
			if (t[i] != t[j])   //ֻ��ǰ�������ַ�����ͬʱ�Żᰴǰ����㷨������next�� ��next[i] = j
				next[i] = j;
			else
				next[i] = next[j];        //��ǰ�������ַ���ͬʱ��������ǰ�ң��ܹ����ٱȽϵĴ���
		}
		else
		{
			j = next[j];
		}
	}
}

int index(char *s, char *t, int pos)
{
	int i = pos;
	int j = 0;
	int len1 = strlen(s);
	int len2 = strlen(t);
	while (i < len1&&j < len2)
	{
		if (j == -1 || s[i] == t[j])//��һ���ַ�����ƥ������ַ���ȵ����
		{
			i++;
			j++;
		}
		else   //iָ�벻����,jָ��
		{
			//i=i-j+1;
			j = next[j];
		}
	}
	if (j >= len2)
		return i - len2;
	else
		return -1;
}

//http://blog.csdn.net/daringpig/article/details/7634872
int main()
{
	int pos;
	gets(s);
	gets(t);
	scanf("%d", &pos);//0

	get_nextval(t, next);
	int no = index(s, t, pos);
	if (no > 0)
		printf("String s contains a substring %d\n",no);
	else
		printf("String s doesn't contain a substring %d\n", no);
	return 0;
}