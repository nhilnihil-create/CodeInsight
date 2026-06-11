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

void paint(vector< vector<int> > &white, int sx, int sy, int x, int y) {
	for(int i = sx; i < x; ++i) {
		for(int j = sy; j < y; ++j) {
			white[i][j] = 0;
		}
	}
}

int main(void) {
	int w, h, n;
	cin >> w >> h >> n;
	
	vector< vector<int> > white(w, vector<int>(h, 1));
	
	for(int i = 0; i < n; ++i) {
		int x, y, a;
		cin >> x >> y >> a;
	
		if( a == 1 ) paint(white, 0, 0, x, h);
		if( a == 2 ) paint(white, x, 0, w, h);
		if( a == 3 ) paint(white, 0, 0, w, y);
		if( a == 4 ) paint(white, 0, y, w, h);
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
