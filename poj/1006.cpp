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
扩展欧几里得：ax+by=gcd(a,b)的解x0，y0
通解为x = x0 + (b/gcd)*t, y = y0 - (a/gcd)*t，t为任意整数
参数：ax + by = gcd中参数
返回值：gcd(a,b)
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
中国剩余定理（CRT）
求解同余方程组
x = a1 (mod m1)
x = a2 (mod m2)
...
x = an (mod mn)
x在模M = m1*m2*...*mn下的解唯一
参数：同余方程组参数a数组，m数组
返回值：解x
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