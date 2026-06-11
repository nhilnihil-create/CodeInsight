#include <iostream>
using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair <long long, long long>, null_type, less<pair <long long, long long> >, rb_tree_tag, tree_order_statistics_node_update>

const int N = 200 * 1000 + 7;

long long a[N];
int dp[N];
long long ps[N];
ordered_set s;
int32_t main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ps[i] = ps[i - 1] + a[i];
		ps[i] -= k;
	}
	long long ans = 0;
	for (int i = n; i; i--) {
		pair <long long, long long> p = {ps[i], i};
		s.insert(p);
		pair <long long, long long> p2 = {ps[i - 1], i - 1};
		int x = s.order_of_key(p2);
		ans += n - i - x + 1;
	//	cout << i << " " << x << " " << p.first << " " << p2.first << endl;
	}
	cout << ans;
	return 0;
}
