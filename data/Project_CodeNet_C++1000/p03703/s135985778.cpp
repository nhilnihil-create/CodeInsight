#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<19, mod = 1e9 + 7, i2 = (mod+1)/2;
ll n, k, f[maxn];
#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	ll p = 0, ans = 0;
	oset x;
	x.insert({0, -1});
	for(int t, i = 0; i < n; i++) {
		cin >> t; t -= k;
		p += t;
		ans += x.order_of_key({p+1, -1});
		x.insert({p, i});
	}
	cout << ans;
	return 0;
}
