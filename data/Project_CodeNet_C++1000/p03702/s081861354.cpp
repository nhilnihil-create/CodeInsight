#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define pb push_back
#define all(x) (x).begin(), (x).end()
template <typename T> using ord_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5 + 123;
ll n, a, b, h[N];

bool check(ll x) {
	ll res = 0;
	for (int i = 0; i < n; i++) {
		ll cur = (h[i] - x * b);
		res += (max(0ll, cur) + a - 1) / a;
	}
	return res <= x;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n >> a >> b;
	a -= b;
	for (int i = 0; i < n; i++) cin >> h[i];
	int l = -1, r = 1e9 + 123;
	while (l < r - 1) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid;
	}
	cout << r;
}
