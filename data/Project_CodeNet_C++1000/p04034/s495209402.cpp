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
	int n, m;
	cin >> n >> m;
	
	vector<int> x(m), y(m);
	vector<int> cnt(n, 1);
	vector<int> on(n, 0);
	on[0] = 1;
	
	for(int i = 0; i < m; ++i) {
		cin >> x[i] >> y[i];
		x[i]--; y[i]--;
		
		if( on[x[i]] && !on[y[i]] ) {
			on[y[i]] = 1;
		}
		
		cnt[x[i]]--; cnt[y[i]]++;
		
		if( cnt[x[i]] == 0 ) {
			on[x[i]] = 0;
		}
	}
	
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if( on[i] ) ans++;
	}
	
	cout << ans << endl;

	return 0;
}
