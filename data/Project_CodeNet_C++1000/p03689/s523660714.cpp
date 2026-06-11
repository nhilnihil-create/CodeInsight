#include <iostream>
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

int a = 1e+8;
int H, W, h, w;
int ans[500][500];

int main() {
	int i, j;
	
	cin >> H >> W >> h >> w;
	
	if (H % h == 0 && W % w == 0) { cout << "No" << endl; return 0; }
	if (W % w != 0) {
		rep(i, H) {
			rep(j, W) {
				if (j % w == 0) ans[i][j] = a;
				else ans[i][j] = -(a / (w - 1) + 1);
			}
		}
	}
	else {
		rep(j, W) {
			rep(i, H) {
				if (i % h == 0) ans[i][j] = a;
				else ans[i][j] = -(a / (h - 1) + 1);
			}
		}
	}
	
	cout << "Yes" << endl;
	rep(i, H) {
		rep(j, W) {
			cout << ans[i][j];
			if (j + 1 < W) cout << " ";
		}
		cout << endl;
	}
	return 0;
}