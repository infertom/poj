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
返回值：最小的x0（可选为正整数还是非负数），-1表示不存在解
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


int n;
ll a[2], m[2];
int main()
{
	//freopen("in.txt", "r", stdin);

	while ( scanf("%d", &n) != EOF )
	{
		scanf("%lld%lld", &m[0], &a[0]);
		bool flag = true;
		n--;
		for (int i = 1; n; i^=1, n--){
			scanf("%lld%lld", &m[i], &a[i]);
			if ( !flag ) continue;
			ll x, y;
			ll k = extend_cal(m[i^1], -m[i], a[i] - a[i^1]);
			ll gcd = extend_Euclid(m[i^1], m[i], x, y);
			if ( k == -1  ) {
				flag = false;
				continue;
			}
			//printf("x1=%lld\n", k);
			a[i] = a[i^1] + m[i^1] * k;
			m[i] = m[i^1] / gcd * m[i];
		}
		if ( flag ) printf("%lld\n", a[n^1]);
		else printf("-1\n");
	}

	return 0;
}*/