#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
ll n; // n <= 1e6
ll f[1000010], s[1000010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	f[0] = 1; f[1] = 1; f[2] = 1;
	s[0] = 1; s[1] = 2; s[2] = 3;
	for(ll i = 3; i <= n; ++i)
	{
		f[i] = (f[i-1] + s[i-3])%mod;
		s[i] = (s[i-1] + f[i])%mod;
	}
	ll ans = 0;
	for(ll i = 0; i <= n-2; ++i) ans = (ans + f[i])%mod;
	ans = (n-1)*(n-1)%mod*ans%mod;
	ans = (((n-1)*f[n-1]%mod + f[n])%mod + ans)%mod;
	for(ll i = 1; i <= n-1; ++i) ans = (ans+f[i-1]*i)%mod;
	cout << ans;
	return 0;
}