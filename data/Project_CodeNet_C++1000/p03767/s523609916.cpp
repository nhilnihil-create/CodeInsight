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
	
	vector<ll> a(3 * n);
	for(int i = 0; i < 3 * n; ++i) {
		cin >> a[i];
	}		
	
	sort(a.rbegin(), a.rend());
	
	ll ans = 0LL;
	for(int i = 0; i < n; ++i) {
		ans += a[i * 2 + 1];
	}
	
	cout << ans << endl;
	
	return 0;
}
