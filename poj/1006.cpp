/*
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

/ ************************************************************************ /
/ * 
��չŷ����ã�ax+by=gcd(a,b)�Ľ�x0��y0
ͨ��Ϊx = x0 + (b/gcd)*t, y = y0 - (a/gcd)*t��tΪ��������
������ax + by = gcd�в���
����ֵ��gcd(a,b)
* /
/ ************************************************************************ /
ll extend_Euclid(ll a, ll b, ll &x, ll &y)
{
	if ( b == 0 ){
		x = 1;
		y = 0;
		return a;
	}
	ll gcd = extend_Euclid(b, a%b, x, y);
	ll temp = x;
	x = y;
	y = temp - a / b * y;
	return gcd;
}


/ ************************************************************************ /
/ * 
�й�ʣ�ඨ��CRT��
���ͬ�෽����
x = a1 (mod m1)
x = a2 (mod m2)
...
x = an (mod mn)
x��ģM = m1*m2*...*mn�µĽ�Ψһ
������ͬ�෽�������a���飬m����
����ֵ����x
* /
/ ************************************************************************ /
ll xCRT(int a[], int m[], int n)
{
	ll M = 1;
	ll ans = 0;
	for (int i = 0; i < n; i++) M *= m[i];
	for (int i = 0; i < n; i++){
		ll x, y;
		int Mi = M / m[i];
		extend_Euclid(Mi, m[i], x, y);
		ans = (ans + Mi * x * a[i]) % M;
	}
	return (ans + M) % M;
}

int p, e, i, d;
int a[10], m[10];

int main()
{
	int t = 1;
	m[0] = 23;
	m[1] = 28;
	m[2] = 33;
	while ( scanf("%d%d%d%d", &a[0], &a[1], &a[2], &d) != EOF && !(a[0] == -1 && a[1] == -1 && a[2] == -1 && d == -1))
	{
		ll ans = xCRT(a, m, 3);
		ll k = 23 * 28 * 33;
		ans -= d;
		if ( ans <= 0 ) ans += k;
		printf("Case %d: the next triple peak occurs in %lld days.\n", t++, ans);
	}

	return 0;
}*/