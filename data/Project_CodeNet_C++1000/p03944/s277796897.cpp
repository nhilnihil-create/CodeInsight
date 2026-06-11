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
	int w, h, n;
	cin >> w >> h >> n;
	
	int ans = h * w;
	int maxx = w, maxy = h, minx = 0, miny = 0;
	
	for(int i = 0; i < n; ++i) {
		int x, y, a;
		cin >> x >> y >> a;
		
		if( a == 1 ) {
			ans -= max(0, x - minx) * max(0, maxy - miny);
			minx = max(minx, x);
		}
		
		if( a == 2 ) {
			ans -= max(0, maxx - x) * max(0, maxy - miny);
			maxx = min(maxx, x);
		}
		
		if( a == 3 ) {
			ans -= max(0, maxx - minx) * max(0, y - miny);
			miny = max(miny, y);
		}
		
		if( a == 4 ) {
			ans -= max(0, maxx - minx) * max(0, maxy - y);
			maxy = min(maxy, y);
		}
	}
	
	cout << max(0, ans) << endl;
	
	return 0;
}
