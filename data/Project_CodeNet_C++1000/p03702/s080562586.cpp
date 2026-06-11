#include<iostream>
#include<algorithm>
#include<cstdio>
#define ll long long
#define maxn 100005
#define inf 0x3f3f3f3f
using namespace std;
ll a[maxn];
ll r=0, l = 1;
ll n, b, s,sum=0;
int run(ll x)
{
	ll tmp = b - s;
	ll num = x*s;
	sum = 0;
	for (int i = n-1;i >= 0;i--)
	{
		
		if (a[i] - num > 0)
		{
			if ((a[i] - num) % tmp)
				sum += (a[i] - num) / tmp + 1;
			else
				sum += (a[i] - num) / tmp;
		}
	}
	if (sum > x)
		return 1;
	else
		return 0;
}
int main()
{
	cin >> n >> b >> s;
	for (int i = 0;i < n;i++)
	{
		scanf("%lld", &a[i]);
		r += a[i] / s + 1;
	}
	sort(a, a + n);
	while (l < r)
	{
		ll mid = (r + l) / 2;
		if (run(mid))
			l = mid + 1;
		else
			r = mid;
	}
	printf("%lld\n",r);
	return 0;
}