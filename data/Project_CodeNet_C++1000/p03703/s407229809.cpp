
// Problem : E - Meaningful Mean
// Contest : AtCoder Regular Contest 075
// URL : https://atcoder.jp/contests/arc075/tasks/arc075_c
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using ll = long long;
using namespace std;

// begin of indexed_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;
// end of indexed_set

#define size(x) (int)x.size()

const int N = 1e6 + 1, mod = 1e9 + 7;

int n, k;
ll ans = 0, a[N];
indexed_multiset im;

int main() { cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	im.insert({a[n] - 1ll * k * n, n});
	for (int i = n - 1; i >= 0; i--) {
		ans += size(im) - im.order_of_key({a[i] - 1ll * k * i, 0});
		im.insert({a[i] - 1ll * k * i, i});
	}
	cout << ans;
}
