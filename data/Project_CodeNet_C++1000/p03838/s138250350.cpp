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
	int x, y;
	cin >> x >> y;
	
	int ans = 0;
	if( x != 0 && y != 0 && x != y && abs(x) == abs(y) ) ans++;
	
	else if( x > y ) {
		if( (x < 0 && y < 0) || (x > 0 && y > 0) ) {
			ans += abs(x - y);
			ans += 2;
		} else if( x >= 0 && y <= 0 ) {
			ans++;
			ans += abs(x - abs(y));
		}
	} else if( x < y ) {
		if( (x <= 0 && y <= 0) || (x >= 0 && y >= 0) ) {
			ans += abs(y - x);
		} else if( x < 0 && y > 0 ) {
			ans += abs(abs(x) - y);
			ans++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
