#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
ll a[200010];
ll sum[200010];
int main()
{
	ll n;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	ll dap = 1e18;
	for (int i = 1; i < n; i++)
	{
		dap = min(dap, abs(sum[i] - (sum[n] - sum[i])));
	}
	printf("%lld", dap);
}