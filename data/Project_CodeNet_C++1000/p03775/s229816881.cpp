#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;

int len(ll x) {
	int res = 0;
	while (x > 0)
	{
		res++;
		x /= 10;
	}
	return res;
}
int main() {
	ll n;
	cin >> n;
	int ans = INF;
	for (ll i = 1; i*i <= n; i++)
	{
		if (n % i != 0) continue;
		ans = min(ans, len(n/i));
	}
	cout << ans << endl;
	return 0;
}