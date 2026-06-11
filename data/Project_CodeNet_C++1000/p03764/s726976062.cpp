#include <bits/stdc++.h>
using namespace std;
#define rep(i, N)  for(int i = 0; i < (N); i++)
typedef long long ll;
const int MOD = 1000000007;
int n, m;
ll x[100000], y[100000];

ll xs[100000];
ll sy;
void solve(){
	ll ans = 0;
	rep(i, n - 1)
		xs[i] = ((x[i + 1] - x[i]) * (i + 1) * (n - i - 1)) % MOD;
	rep(i, m - 1)
		sy = (sy + (y[i + 1] - y[i]) * (i + 1) * (m - i - 1)) % MOD;
	rep(i, n - 1)
		ans = (ans + xs[i] * sy) % MOD;
	cout<<ans<<endl;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, n)
		cin >> x[i];
	rep(i, m)
		cin >> y[i];
	solve();
	return 0;
}
