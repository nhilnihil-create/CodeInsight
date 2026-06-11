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
	ll c, k;
	cin >> n >> c >> k;
	
	vector<ll> t(n);
	for(int i = 0; i < n; ++i) {
		cin >> t[i];
	}
	
	sort(t.begin(), t.end());
	
	int cnt = 0;
	int ans = 0;
	ll nop = 1;
	for(int i = 1; i < n; ++i) {
		ll limit = t[cnt] + k;
	
		if( t[i] <= limit && nop < c ) { 
			nop++;
		} else {
			ans++;
			cnt = i;
			nop = 1;
		}
	}
	
	ans++;
	cout << ans << endl;
	
	return 0;
}
