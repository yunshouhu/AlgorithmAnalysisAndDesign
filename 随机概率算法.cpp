
#include "RandomNumber.h"
#define LEN(arr) sizeof(arr)/sizeof(arr[0])

//用随机投点法计算π值 
double Darts(int n){	static RandomNumber dart;	int k = 0;	for (int i = 1; i <= n; i++){		double x = dart.fRandom();		double y = dart.fRandom();		if ((x*x + y*y) <= 1) k++;	}	return 4 * k / double(n);}void Swap(int &a, int &b){	int c = a;	a = b;	b = c;}template<class Type> void Shuffle(Type a[],int n){	static RandomNumber rnd;	for (int i = 0; i < n; i++)	{		int j = rnd.Random(n - i) + i;		Swap(a[i], a[j]);	}}void show(int arr[], int len){	for (int i = 0; i < len; i++)	{		cout << arr[i]<<" ";	}	cout << endl;}int gcd(int a, int b) {	return a == 0 ? b : gcd(b % a, a);}void Pollard(int n){	RandomNumber rnd;	int i = 1;	int x = rnd.Random(n);	int y = x;	int k = 2;	while (true) {		i++;		x = (x*x - 1) % n;		int d=gcd(y-x,n);		if ((d > 1) && (d < n))		{			cout << d << endl;			break;		}					if (i == k) {			y = x;			k *= 2;		}	}}/**template<class Type>bool Majority(Type *T, int n){	RandomNumber rnd;	int i=rnd.Random(n) + 1;	Type x = T[i]; 	int k=0;	for (int j=1;j<=n; j++)		if (T[j]==x)			k++;	return (k>n/2);}template<class Type>bool MajorityMC(Type *T, int n, double e){	int k = ceil(log(1/e) /log(2));	for (int i = 1; i <= k; i++)	{		if (Majority(T, n))		{			return true;		}				}	return false;}*/void power(unsigned int a, unsigned int p,	unsigned int n, unsigned int &result,	bool &composite){	unsigned int x;	if (p == 0) result = 1;	else {		power(a, p / 2, n, x, composite); 		result = (x*x) % n;           		if ((result == 1) && (x != 1) && (x != n - 1))			composite = true;		if ((p % 2) == 1)     			result = (result*a) % n;	}}
bool Prime(unsigned int n){	RandomNumber rnd;	unsigned int a, result;	bool composite = false;	a = rnd.Random(n - 3) + 2;	power(a, n - 1, n, result, composite);	if (composite || (result != 1)) return false;	else return true;}

//第7章  概率算法
int main()
{
	cout << Darts(45) << endl;
	int arr[] = {1,2,3,4,5,6,7};
	int len = LEN(arr);
	Shuffle(arr, len);
	show(arr, len);
	//Pollard(22);
	//bool ret= MajorityMC(&arr, 5, 4);
	cout << Prime(130) << endl;
	return 0;
}