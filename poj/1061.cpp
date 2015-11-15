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
����ͨʽax+by=c�����ҽ���c%gcd(a,b)==0ʱ��������չŷ����ý�
������ax + by = c�в���
����ֵ����С��x0����ѡΪ���������ǷǸ�����
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
	//return ((x % b) > 0)? (x%b):(x%b+b);//������С������
	return (x % b + b) % b;//������С�Ǹ���
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