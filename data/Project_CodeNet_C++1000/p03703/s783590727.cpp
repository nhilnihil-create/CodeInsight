#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<pair<long long, long long>, null_type, less<pair<long long, long long> >, rb_tree_tag, tree_order_statistics_node_update>
const int N = 2e5 + 10;
ordered_set st;
long long ps[N], ans;
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> ps[i + 1];
		ps[i + 1] += ps[i] - k;
	}
	for (int i = 0; i <= n; i++) {
		auto x = st.order_of_key({ps[i], i});
		ans += x;
		st.insert({ps[i], -i});
	}
	cout << ans;
	return 0;
}
