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
对于通式ax+by=c，当且仅当c%gcd(a,b)==0时可利用扩展欧几里得解
参数：ax + by = c中参数
返回值：最小的x0（可选为正整数还是非负数）
* /
/ ************************************************************************ /
ll extend_cal(ll a, ll b, ll c)
{
	ll x, y;
	ll gcd = extend_Euclid(a, b, x, y);
	if ( c % gcd ) return -1;
	x *= c/gcd;
	b /= gcd;
	if ( b < 0 ) b = -b;
	//return ((x % b) > 0)? (x%b):(x%b+b);//返回最小正整数
	return (x % b + b) % b;//返回最小非负数
}

int main()
{
	int x, y, m, n, l;
	while ( scanf("%d%d%d%d%d", &x, &y, &m, &n, &l) != EOF )
	{
		ll ans = extend_cal(m-n, l, y-x);
		if ( ~ans ) printf("%lld\n", ans);
		else printf("Impossible\n");
	}

	return 0;
}*/