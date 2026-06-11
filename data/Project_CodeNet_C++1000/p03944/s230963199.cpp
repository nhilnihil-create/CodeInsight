#include<iostream>

using namespace std;

int main() {
	int W, H, N, x[110], y[110], a[110];
	int x_min = 0, x_max = 1000, y_min = 0, y_max = 1000;

	cin >> W >> H >> N;
	x_max = W;
	y_max = H;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i] >> a[i];
	}
	for (int i = 0; i < N; i++) {
		if (a[i] == 1) {
			if (x_min < x[i]) {
				x_min = x[i];
			}
		}
		if (a[i] == 2) {
			if (x_max > x[i]) {
				x_max = x[i];
			}
		}
		if (a[i] == 3) {
			if (y_min < y[i]) {
				y_min = y[i];
			}
		}
		if (a[i] == 4) {
			if (y_max > y[i]) {
				y_max = y[i];
			}
		}
	}
	if (x_min > x_max || y_min > y_max) {
		cout << 0 << endl;
	}
	else {
		cout << (x_max - x_min) * (y_max - y_min) << endl;
	}

	return 0;
}