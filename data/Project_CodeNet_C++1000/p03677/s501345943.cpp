#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
pair<ll,pair<ll, ll>> ch1[100010];
ll a[100010];
ll gap[100010];
int main()
{
	ll n, m;
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	ll dap = 0;
	for (int i = 2; i <= n; i++)
	{
		ll ch = (a[i] + m - a[i - 1]) % m;
		dap += ch;
		ch--;
		ch1[a[i]].second.first++;
		ch1[a[i]].first += ch;
		ll x = a[i] - ch;
		if ((x <= 0))
		{
			x+=m;
			ch1[x].second.second--;
		}
		else
		{
			ch1[x].second.first--;
		}
	}
	ll xx = 0;
	ll ch = 0;
	for (int i = m; i >= 1; i--)
	{
		xx += ch1[i].first;
		ch += ch1[i].second.first;
		gap[i] = xx;
		xx -= ch;
	}
	for (int i = m; i >= 1; i--)
	{
		ch += ch1[i].second.second;
		gap[i] += xx;
		xx -= ch;
	}
	ll jj = 0;
	for (int i = 1; i <= m; i++)
	{
		jj = max(jj, gap[i]);
	}
	printf("%lld", dap - jj);
}