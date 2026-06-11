#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair <long long, int>, null_type, less<pair <long long, int> >, rb_tree_tag, tree_order_statistics_node_update>

const int N = 2e5 + 7;
map <long long, int> cnt;
long long a[N], n, k;
ordered_set s;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i], a[i] -= k;
	long long res = 0, t = 0;
	for (int i = 1; i <= n; i++) {
		s.insert({-t, cnt[-t]});
		cnt[-t]++;
		t += a[i];
		res += i - s.order_of_key({-t, 0});
	}
	cout << res;


	return 0;
}







