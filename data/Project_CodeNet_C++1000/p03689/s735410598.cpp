#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) (V).begin(),(V).end()

int main(){
	ll H, W, h, w;
	cin >> H >> W >> h >> w;

	if (H%h == 0 && W%w == 0) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	vector<vector<int>> ANS(H,vector<int>(W, 501));
	for (int i = 0;i < H;i++) {
		for (int j = 0;j < W;j++) {
			if (i%h == h - 1 && j%w == w - 1)
				ANS[i][j] = -501 * (h*w - 1) - 1;
			cout << ANS[i][j] << " ";
		}
		cout << endl;
	}
}