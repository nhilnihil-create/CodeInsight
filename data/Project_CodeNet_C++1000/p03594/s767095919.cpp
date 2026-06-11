#include <string>
#include <iostream>
using namespace std;
int H, W, d; string col = "RGBY";
int main() {
	cin >> H >> W >> d;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << col[(i + j) / d % 2 * 2 + (i - j + 4 * W) / d % 2];
		}
		cout << endl;
	}
	return 0;
}