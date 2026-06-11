#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int64_t H, W;
	cin >> H >> W;

	int64_t dif = H * W;
	for (int i = 1; i < H; i++) {
		int64_t a, b, c, x;
		a = i * W;
		//cout << "a:" << a << endl;
		
		if ((H - i) % 2 == 0) {
			b = (H - i) / 2 * W;
			//cout << "b:" << b << endl;
			x = abs(a - b);
			if (x < dif) dif = x;
		}

		b = (H - i) * (W / 2);
		c = (H - i) * (W - (W / 2));
		//cout << "b:" << b << endl;
		x = abs(max(max(a, b), c) - min(min(a, b), c));
		if (x < dif) dif = x;

		//cout << dif << endl;
	}

	for (int i = 1; i < W; i++) {
		int64_t a, b, c, x;
		a = i * H;

		if ((W - i) % 2 == 0) {
			b = (W - i) / 2 * H;
			x = abs(a - b);
			if (x < dif) dif = x;
		}

		b = (W - i) * (H / 2);
		c = (W - i) * (H - (H / 2));
		x = abs(max(max(a, b), c) - min(min(a, b), c));
		if (x < dif) dif = x;
	}

	cout << dif << endl;
}