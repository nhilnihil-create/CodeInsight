#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll a[100010];
int main()
{
	ll n,m,k;
	scanf("%lld %lld %lld", &n,&m,&k);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	ll xx = m - k;
	ll left = 0;
	ll dap = 1234567890;
	ll right = 1234567890;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll ch = mid;
		for (int i = 0; i < n; i++)
		{
			ll oo = a[i] - mid*k;
			ll mm = 0;
			if (oo > 0)
			{
				mm = (oo / xx);
				if (oo % xx)
					mm++;
			}
			ch -= mm;
		}
		if (ch >= 0)
		{
			right = mid - 1;
			dap = min(dap, mid);
		}
		else
			left = mid + 1;
	}
	printf("%lld\n", dap);
}