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
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	int n;
	cin >> n;
	
	vector<ll> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];	
	}
	
	sort(a.begin(), a.end());
	
	vector<ll> sum(n + 1, 0LL);
	for(int i = 0; i < n; ++i) {
		sum[i + 1] = sum[i] + a[i];
	}
	
	vector<bool> ok(n + 1, false);
	for(int i = 1; i < n; ++i) {
		if( 2 * sum[i] >= a[i] ) ok[i - 1] = true;
	}
	
	int ans = 1;
	for(int i = 0; i < n - 1; ++i) {
		if( ok[i] ) ans++;
		else ans = 1;
	}
	
	cout << ans << endl;
	
	return 0;
}
