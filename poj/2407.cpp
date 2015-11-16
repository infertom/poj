/*
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int n;

/ ************************************************************************ /
/ * 

* /
/ ************************************************************************ /
const int MAXEULER = 1e6 + 100;
int euler[MAXEULER];
void xEuler()
{
	memset(euler, 0, sizeof euler);
	euler[1] = 1;
	for (int i = 2; i < MAXEULER; i++){
		if ( euler[i] ) continue;
		for (int j = i; j < MAXEULER; j += i){
			if ( !euler[j] ) euler[j] = j;
			euler[j] -= euler[j] / i;
		}
	}
}

/ ************************************************************************ /
/ * 
��ӡ������
MAXPRIME��������������ޣ������������ֵ
���飺
prime[i]��ŵ�i+1����������Ŵ�0��ʼ��
isPrime[i]��ʾ����i�Ƿ�Ϊ���������ʾ��������
����ֵ��������֮�������ĸ���
* /
/ ************************************************************************ /
const int MAXPRIME = 1e6 + 100;
int prime[MAXPRIME];
bool isPrime[MAXPRIME];
int xPrime()
{
	int cnt = 0;
	memset(prime, 0, sizeof prime);
	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < MAXPRIME; i++){
		if ( !isPrime[i] ) continue;
		prime[cnt++] = i;
		if ( (ll)i * i >= (ll)MAXPRIME ) continue;
		for (int j = i * i; j < MAXPRIME; j += i) isPrime[j] = false;
	}
	
	return cnt;
}

int primeNum;
int cal(int x)
{
	int cnt = x;
	for (int i = 2; i < primeNum && i * i <= x; i++){
		if ( isPrime[i] && (x % i == 0) ) cnt -= cnt / i;
		while ( x % i == 0 ) x /= i;
	}
	if ( x != 1 ) cnt -= cnt / x;

	return cnt;
}

int main()
{
	primeNum = xPrime();
	while ( scanf("%d", &n) != EOF && n )
	{
		printf("%d\n", cal(n));
	}

	return 0;
}*/