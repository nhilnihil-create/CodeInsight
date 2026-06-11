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

	map<ll, ll> mp;
	for(int i = 0; i < n; ++i) {
		ll a, b;
		cin >> a >> b;
		mp[a] += b;
	}
	
	int ans = 0;
	for(auto& x : mp) {
		if( x.second >= k ) {
			ans = x.first;
			break;
		}
		
		k -= x.second;
	}
	
	cout << ans << endl;
	
	return 0;
}
