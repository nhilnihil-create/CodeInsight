#include <bits/stdc++.h>
using namespace std;

int c[110][110];
int n;
int a[11000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int h, w; cin >> h >> w;
	cin >> n;
	for(int i = 0; i < n; ++ i) cin >> a[i];
	int x = 0, y = 0, dir = 1;
	for(int i = 0; i < n; ++ i) {
		for(int j = 0; j < a[i]; ++ j) {
			c[x][y] = i + 1;
			if(y == w - 1 && dir == 1 || y == 0 && dir == -1) {
				dir *= -1;
				++ x;
			} else {
				y += dir;
			}
		}
	}
	for(int i = 0; i < h; ++ i) for(int j = 0; j < w; ++ j) cout << c[i][j] << " \n"[j == w - 1];
	return 0;
}
