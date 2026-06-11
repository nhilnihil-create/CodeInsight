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
	
	vector<bool> ok(n, false);
	vector<int> box(n, 1);
	
	ok[0] = true;
	for(int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		
		if( ok[x] ) ok[y] = true;
	
		box[x]--; box[y]++;
		
		if( box[x] == 0 ) ok[x] = false;
	}
	
	int ans = 0;
	for(auto v : ok) {
		if( v ) ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}
