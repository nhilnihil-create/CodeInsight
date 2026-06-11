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



int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	ll x, y;
	cin >> x >> y;
	if (abs(x - y) <= 1) cout << "Brown";
	else cout << "Alice";
}
