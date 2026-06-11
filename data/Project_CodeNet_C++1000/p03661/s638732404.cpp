#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9) + 7;

int main(void) {
	int n;
	cin >> n;
	
	vector<ll> a(n);
	ll sum = 0LL;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	
	ll ans = 1e18;
	ll m = 0LL;
	for(int i = 0; i < n - 1; ++i) {
		m += a[i];
		ans = min(ans, abs(sum - 2 * m));
	}
	
	cout << ans << endl;
	
	return 0;
}
