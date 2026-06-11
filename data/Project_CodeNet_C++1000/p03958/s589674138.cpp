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
	int k, t;
	cin >> k >> t;
	
	vector<int> a(t);
	for(int i = 0; i < t; ++i) {
		cin >> a[i];
	}

	sort(a.begin(), a.end(), greater<int>());
	
	for(int i = 1; i < t; i++) {
		if( a[i] == 0 ) continue;
		
		a[i - 1] -= a[i];
		a[i] = 0;
	}
	
	int ans = 0;
	for(int i = 0; i < t; ++i) {
		ans += a[i];
	}

	if( ans > 0 ) ans--;
	if( ans < 0 ) ans = 0;
	
	cout << ans << endl;
	
	return 0;
}
