#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
#include <iomanip>
#include <bitset>
#include <numeric>
#include <queue>
#include <map>
#include <cstdint>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
const long long mod = 1000000007;
typedef long long int ll;
typedef pair<ll, ll> P;
const vector<int> di = { -1, 0, 1, 0 };
const vector<int> dj = { 0, 1, 0, -1 };
const double PI = 3.14159265358979323846;


int main() {

	int h, w, n;
	cin >> h >> w >> n;
	vector<int> a(n);
	rep(i, n) cin >> a.at(i);
	
	deque<int> color_index;
	rep(i, n) {
		rep(j, a.at(i)) {
			color_index.push_back(i + 1);
		}
	}


	vector<vector<int>> image(h, vector<int>(w, 0));

	rep(i, h) {
		int x = i;
		if (x % 2 == 0) {
			for (int j = 0; j < w; j++) {
				int y = j;
				image[x][y] = color_index.at(0);
				color_index.pop_front();
			}
		}
		else if (x % 2 != 0) {
			for (int j = (w - 1); j > -1; j--) {
				int y = j;
				image[x][y] = color_index.at(0);
				color_index.pop_front();
			}
		}
	}
	rep(i, h) {
		rep(j, w) {
			cout << image[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
	
}

