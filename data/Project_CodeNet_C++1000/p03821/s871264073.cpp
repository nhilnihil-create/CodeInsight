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
	
	vector< pair<ll, ll> > p(n);
	for(int i = 0; i < n; ++i) {
		ll a, b;
		cin >> a >> b;
		
		p[i] = {a, b};
	}
	
	ll cnt = 0LL;
	ll prev = 0LL;
	for(int i = n - 1; i >= 0; i--) {
		p[i].first += prev;
		
		if( p[i].first % p[i].second != 0 ) {
			cnt = p[i].second - (p[i].first % p[i].second);
		}
		
		prev += cnt;
		cnt = 0;
	}
	
	cout << prev << endl;
	
	return 0;
}
