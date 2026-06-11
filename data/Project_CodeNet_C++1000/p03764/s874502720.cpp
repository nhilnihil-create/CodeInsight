#include<cstdio>
#define ll long long
#define mod 1000000007
using namespace std;
ll a[100010];
ll b[100010];
int main()
{
	ll n, m;
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i < m; i++)
		scanf("%lld", &b[i]);
	ll dap = 0,dap1=0;
	ll ch = 0, ch1 = 0;
	for (int i = 0; i < n; i++)
	{
		dap += (a[i] - a[0]);
	}
	for (int i = 0; i < m; i++) {
		dap1 += (b[i] - b[0]);
	}
	ch = dap;
	ch1 = dap1;
	for (int i = 1; i < n; i++)
	{
		dap -= ((a[i] - a[i - 1])*(n - i));
		ch += dap;
		ch %= mod;
	}
	for (int i = 1; i < m; i++)
	{
		dap1 -= ((b[i] - b[i-1])*(m - i));
		ch1 +=dap1;
		ch1 %= mod;
	}
	printf("%lld", (ch*ch1) % mod);
}