#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll get(int num)
{
	vector<ll>v;
	for (int i = 0; i < num; i++)
	{
		ll z;
		scanf("%lld", &z);
		v.push_back(z);
	}
	ll ans = 0;
	for (ll i = 0; i < num - 1; i++)
	{
		ll t = (i + 1)*(num - i - 1) % mod;
		ans = (ans + t*(v[i + 1] - v[i])) % mod;
	}
	return ans;
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	ll s = get(a), t = get(b);
	printf("%lld\n", s*t%mod);
}