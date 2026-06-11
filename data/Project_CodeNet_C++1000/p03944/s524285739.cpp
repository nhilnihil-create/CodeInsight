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
	
	vector< vector<int> > white(w, vector<int>(h, 1));
	
	for(int i = 0; i < n; ++i) {
		int x, y, a;
		cin >> x >> y >> a;
	
		if( a == 1 ) {
			for(int j = 0; j < x; ++j) {
				for(int k = 0; k < h; ++k) {
					white[j][k] = 0;
				}
			}
		}
		
		if( a == 2 ) {
			for(int j = x; j < w; ++j) {
				for(int k = 0; k < h; ++k) {
					white[j][k] = 0;
				}
			}
		}
		
		if( a == 3 ) {
			for(int j = 0; j < w; ++j) {
				for(int k = 0; k < y; ++k) {
					white[j][k] = 0;
				}
			}
		}
		
		if( a == 4 ) {
			for(int j = 0; j < w; ++j) {
				for(int k = y; k < h; ++k) {
					white[j][k] = 0;
				}
			}
		}
	}
	
	int ans = 0;
	for(int i = 0; i < w; ++i) {
		for(int j = 0; j < h; ++j) {
			if( white[i][j] == 1 ) ans++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
