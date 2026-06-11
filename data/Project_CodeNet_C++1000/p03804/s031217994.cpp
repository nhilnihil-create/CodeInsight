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
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if( i + m - 1 >= n || j + m - 1 >= n ) continue;
			
			bool match = true;
			
			for(int x = 0; x < m; ++x) {
				for(int y = 0; y < m; ++y) {
					if( a[i + x][j + y] != b[x][y] ) match = false;
				}
			}
			
			if( match ) yes = true;
		}
	}
	
	if( yes ) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
