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
#include <iomanip>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i]--;
	}
	
	int ans = 0;
	int now = 0;
	for(int i = 0; i < n; ++i) {
		now = a[now];
		ans++;
		
		if( now == 1 ) break;
	}
	
	if( ans == n ) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
	
	return 0;
}
