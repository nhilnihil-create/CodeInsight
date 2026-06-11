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
	
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	ll ans = 0;
	for(int i = 0; i < n; ++i) { 
		ans += (ll)(a[i] / 2);
		a[i] %= 2;
		
		if( i < n - 1 && a[i + 1] && a[i] ) { 
			ans++;
			a[i]--;
			a[i + 1]--;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
