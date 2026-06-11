#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int W, H, N;
	cin >> W >> H >> N;
	int xl, xr, yd, yu;
	xl = yd = 0;
	xr = W;
	yu = H;
	for (int i = 0; i < N; ++i) {
		int x, y, a;
		cin >> x >> y >> a;
		if (a == 1) {
			if (xl < x) xl = x;
		}
		else if (a == 2) {
			if (x < xr) xr = x;
		}
		else if (a == 3) {
			if (yd < y) yd = y;
		}
		else if (y < yu) yu = y;
	}
	if (xr - xl > 0 && yu - yd > 0) {
		cout << (xr - xl) * (yu - yd) << endl;
	}
	else {
		cout << 0 << endl;
	}
}