#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

#include <iostream>
#include <string>
#include <time.h>
using namespace std;


const unsigned long maxshort = 65535L;
const unsigned long multiplier = 1194211693L;
const unsigned long adder = 12345L;

class RandomNumber {
private:
	// ��ǰ����
	unsigned long randSeed;
public:
	// ���캯��,Ĭ��ֵ0��ʾ��ϵͳ�Զ���������
	RandomNumber(unsigned long s = 0);
	// ����0 ~ n-1֮����������
	unsigned short Random(unsigned long n);
	// ����[0, n-1) ֮������ʵ��
	double fRandom();
};

// ��������
RandomNumber::RandomNumber(unsigned long s)
{
	if (s == 0)
		randSeed = time(0);    //��ϵͳʱ���������
	else
		randSeed = s;
}

// ����0 ~ n-1 ֮����������
unsigned short RandomNumber::Random(unsigned long n)
{
	randSeed = multiplier * randSeed + adder;
	return (unsigned short)((randSeed >> 16) % n);
}

// ����[0, 1)֮������ʵ��
double RandomNumber::fRandom()
{
	return Random(maxshort) / double(maxshort);
}
#endif // RANDOMNUMBER_H
