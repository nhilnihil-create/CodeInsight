#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
 
typedef tree <pii, null_type, less <pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
const int N = 2e5 + 123;
int n, k, a[N], m, fen[N];
ll p[N];
 
void upd(int x) {
	for (; x <= m; x |= (x + 1)) {
		fen[x]++;
	}
}
 
int get(int x) {
	int res = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1) {
		res += fen[x];
	}
	return res;
}
 
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n >> k;
	vll comp;
	comp.pb(0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] -= k;
		p[i] = p[i - 1] + a[i];
		comp.pb(p[i]);
	}
	sort(all(comp));
	comp.erase(unique(all(comp)), comp.end());
	m = comp.size();
	int z = lower_bound(all(comp), 0) - comp.begin() + 1;
	upd(z);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		p[i] = lower_bound(all(comp), p[i]) - comp.begin() + 1;
		ans += get(p[i]);
		upd(p[i]);
	}
	cout << ans;
}
