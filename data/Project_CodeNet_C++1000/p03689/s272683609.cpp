#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 10000000;
const long long inf = 1ll<<61;
typedef pair<int, int> P;
typedef pair<P, int> PP;
typedef pair<int,PP> PPP;
struct edge { int to;  int cost; };

int ans[600][600];
void disp(int h, int w) {
	rep(i, h) {
		rep(j, w) {
			if (j)cout << ' '; cout << ans[i][j];
		}cout << endl;
	}
}
signed main() {
	int H, W, h, w; cin >> H >> W >> h >> w;
	
	rep(i, h) {
		rep(j, w) {
			if (i == h - 1 && j == w - 1)ans[i][j] = -(600*(h*w-1)+1);
			else ans[i][j] = 600;
		}
	}
	
	for (int i = h; i < H; i++) {
		rep(j, W) {
			ans[i][j] = ans[i - h][j];
		}
	}

	rep(i, H) {
		for (int j = w; j < W; j++) {
			ans[i][j] = ans[i][j - w];
		}
	}


	int sum = 0;
	rep(i, H)rep(j, W)sum += ans[i][j];
	if (sum <= 0)puts("No");
	else {
		puts("Yes");
		disp(H, W);
	}
}