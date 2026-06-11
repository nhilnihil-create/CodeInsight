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
	for(int i = 0; i < m; ++i) {
		cin >> x[i] >> y[i];
		x[i]--; y[i]--;
	}
	
	vector<bool> ok(n, false);
	vector<int> box(n, 1);
	
	ok[0] = true;
	for(int i = 0; i < m; ++i) {
		if( ok[x[i]] ) {
			ok[y[i]] = true;
		}
		
		box[x[i]]--;
		box[y[i]]++;
		
		if( box[x[i]] == 0 ) {
			ok[x[i]] = false;
		}
	}
	
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if( ok[i] ) ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}
