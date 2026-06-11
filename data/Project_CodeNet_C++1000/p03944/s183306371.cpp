#include<iostream>
using namespace std;

int main() {
	int w, h, n; cin >> w >> h >> n;
	int xy[105][105];
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			xy[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		int x, y, a; cin >> x >> y >> a;
		if (a == 1) {
			for (int xi = 0; xi < x; xi++) {
				for (int yi = 0; yi < h; yi++) {
					if (xy[xi][yi] == 1)xy[xi][yi]--;
				}
			}
		}
		else if (a == 2) {
			for (int xi = x; xi < w; xi++) {
				for (int yi = 0; yi < h; yi++) {
					if (xy[xi][yi] == 1)xy[xi][yi]--;
				}
			}
		}
		else if (a == 3) {
			for (int xi = 0; xi < w; xi++) {
				for (int yi = 0; yi < y; yi++) {
					if (xy[xi][yi] == 1)xy[xi][yi]--;
				}
			}
		}
		else {
			for (int xi = 0; xi < w; xi++) {
				for (int yi = y; yi < h; yi++) {
					if (xy[xi][yi] == 1)xy[xi][yi]--;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			ans += xy[i][j];
		}
	}
	cout << ans << endl;

	return 0;
}