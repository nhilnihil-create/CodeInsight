#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int h,w,n;
	cin >> h >> w;
	cin >> n;
	vector<int> a(n);
	rep(i,n) {
		cin >> a[i];
	}
	vector<vector<int>> c(h, vector<int>(w));
	int cnt_color = 1;
	int cnt_grid = 0;
	rep(i,h) {
		if (i%2 == 1) {
			for(int j=0;j<w;j++) {
				c[i][j] = cnt_color;
				cnt_grid++;
				if (cnt_grid >= a[cnt_color-1]) {
					cnt_color++;
					cnt_grid = 0;
				}
			}
		}
		else {
			for(int j=w-1;j>=0;j--) {
				c[i][j] = cnt_color;
				cnt_grid++;
				if (cnt_grid >= a[cnt_color-1]) {
					cnt_color++;
					cnt_grid = 0;
				}
			}
		}
	}
	rep(i,h) {
		rep(j,w) {
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
