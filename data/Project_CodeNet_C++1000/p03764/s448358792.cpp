#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int MAX_N = 1e5+10;
int n, m;
int x[MAX_N], y[MAX_N];
ll xpsum[MAX_N], ypsum[MAX_N];

void solve()
{
    for(int i=1;i<=n;++i) (ypsum[i] = ypsum[i-1]+y[i])%=MOD;
    ll ysum = 0;
	for(int i=2;i<=n;++i)(ysum += 1LL*(i-1)*y[i]-ypsum[i-1])%=MOD;
	for(int i=1;i<=m;++i) (xpsum[i] = xpsum[i-1]+x[i])%=MOD;
	ll xsum = 0;
	for(int i=2;i<=m;++i)(xsum += 1LL*(i-1)*x[i]-xpsum[i-1])%=MOD;
	ll ans = xsum*ysum%MOD;
	cout<<ans<<'\n';
}

int main()
{
	cin >> m >> n;
	for(int i=1;i<=m;++i) cin >> x[i];
	for(int i=1;i<=n;++i) cin >> y[i];
	solve();
	return 0;
}