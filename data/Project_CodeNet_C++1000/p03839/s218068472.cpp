#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main()
{
	ll n,k;
	cin >> n >> k;
	vector<ll> a(n);
	for(int i = 0;i<n;i++)cin >> a[i];

	vector<ll> asum(n+1),bsum(n+1);

	for(int i = 0;i<n;i++)
	{
		asum[i+1] = asum[i] + a[i];
		bsum[i+1] = bsum[i] + max(0LL,a[i]);
	}

	ll ans = 0;

	for(int i = 0;i<n-k+1;i++)
	{
		ll now = 0;

		ll A= bsum[i] - bsum[0];
		ll B = max(0LL, asum[i+k] - asum[i]);
		ll C = bsum[n] - bsum[i+k];
	//cout << A << ' ' << B <<' '<< C << endl;
		ans = max(A+B+C,ans);
	}
	cout << ans << endl;

}
