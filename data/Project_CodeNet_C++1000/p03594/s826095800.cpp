#include <iostream>
using namespace std;
int main() {
	int H, W, D;
	cin >> H >> W >> D;
	if (D % 2 == 1) {
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				cout << ((i + j) % 2 == 0 ? "R" : "B");
			}
			cout << endl;
		}
	}
	else {
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				int tx = i + j, ty = i - j + W;
				int cx = (tx / D) % 2, cy = (ty / D) % 2;
				cout << string("RBGY")[cx * 2 + cy];
			}
			cout << endl;
		}
	}
	return 0;
}