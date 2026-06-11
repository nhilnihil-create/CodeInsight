#include "bits/stdc++.h"
using namespace std;

int main() {
	long long H, W, D;
	string C = "RYGB";
	cin >> H >> W >> D;
	if (D % 2 == 0) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				long long U = i + j, V = i - j + W;
				if ((i + j) % 2 == 1) U++, V++;
				U /= 2, V /= 2;
				U %= D, V %= D;
				cout << C[(U < D / 2) * 2 + (V < D / 2)];
			}
			cout << endl;
		}
	}
	else {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cout << C[(i + j) % 2];
			}
			cout << endl;
		}
	}
}