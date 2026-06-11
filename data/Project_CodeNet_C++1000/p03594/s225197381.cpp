#include <bits/stdc++.h>
using namespace std;
int H, W, d;
char C[4] = {'R', 'G', 'B', 'Y'};
int main() {
	cin >> H >> W >> d;
	int cx, cy;
	int color;
	for(int iy = 0; iy < H; iy++) {
		for(int ix = 0; ix < W; ix++) {
			cx = ix + iy + 10000, cy = ix - iy + 10000;
			color = (cx / d) % 2 + ((cy / d) % 2) * 2;
			cout << C[color];
		}
		cout << endl;
	}
	return 0;
}