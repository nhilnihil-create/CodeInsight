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
	
	map<ll, int> mp;
	for(int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		mp[a]++;
	}
	
	vector< pair<ll, int> > p;
	for(auto& x : mp) {
		if( x.second >= 2 ) {
			p.push_back( make_pair(x.first, x.second) );
		}
	}
	
	if( p.empty() ) { 
		cout << 0 << endl;
		return 0;
	}
	
	ll ans = 1LL;
	int en = p.size();
	
	if( p[en - 1].second >= 4 ) ans = p[en - 1].first * p[en - 1].first;
	else ans = p[en - 1].first * p[en - 2].first;
	
	cout << ans << endl;
	
	return 0;
}
