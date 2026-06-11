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
	int n;
	string s, t;
	cin >> n >> s >> t;
	
	int ans = 0;
	for(int i = 0; i < n + 1; ++i) {
		if( s.substr(i) == t.substr(0, n - i) ) {
			ans = n + i;
			break;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
