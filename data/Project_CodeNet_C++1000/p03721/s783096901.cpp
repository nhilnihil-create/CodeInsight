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
	ll k;
	cin >> n >> k;
	
	vector<ll> cnt(1e5 + 1, 0);
	for(int i = 0; i < n; ++i) {
		ll a, b;
		cin >> a >> b;
		cnt[a] += b;
	}
	
	int ans = 0;
	for(int i = 1; i <= 1e5; ++i) {
		if( cnt[i] >= k ) {
			ans = i;
			break;
		}
		
		k -= cnt[i];
	}
	
	cout << ans << endl;
	
	return 0;
}
