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
	int n, m;
	cin >> n >> m;
	
	vector<string> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	vector<string> b(m);
	for(int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	
	bool yes = false;
	for(int i = 0; i + m <= n; ++i) {
		for(int j = 0; j + m <= n; ++j) {
			bool match = true;
			
			for(int k = 0; k < m; ++k) {
				if( a[i + k].substr(j, m) != b[k] ) match = false;
			}
			
			if( match ) yes = true;
		}
	}
	
	if( yes ) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
