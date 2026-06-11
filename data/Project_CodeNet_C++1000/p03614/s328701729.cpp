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
	
	vector<int> p(n);
	for(int i = 0; i < n; ++i) {
		cin >> p[i];
		p[i]--;
	}
	
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if( p[i] == i ) {
			if( i < n - 1 ) swap(p[i], p[i + 1]);
			else swap(p[i - 1], p[i]);
			
			ans++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
