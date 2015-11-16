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
����ֵ����С��x0����ѡΪ���������ǷǸ�������-1��ʾ�����ڽ�
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