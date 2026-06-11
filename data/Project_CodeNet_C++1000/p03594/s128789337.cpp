#include<iostream>
using namespace std;
int H, W, d, c[509][509]; char C[5] = "RBGY";
int main() {
	cin >> H >> W >> d;
	if (d % 2 == 1) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) { if ((i + j) % 2 == 0)c[i][j] = 1; }
		}
	}
	else {
		int dd = d * 2;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				int H1 = i + j, H2 = i - j;
				H1 += d * 10000; H2 += d * 10000;
				c[i][j] = ((H1%dd) / d) * 2 + ((H2%dd) / d);
			}
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)cout << C[c[i][j]]; cout << endl;
	}
	return 0;
}