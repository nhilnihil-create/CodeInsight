#include <iostream>
#include <map>
using namespace std;
int main() {
	int H, W;
	cin >> H >> W;
	int four = (H % 2 == 0 ? H : H - 1) * (W % 2 == 0 ? W : W - 1) / 4;
	int two;
	if (H % 2 == 0 && W % 2 == 0) two = 0;
	else {
		if (H % 2 == 1 && W % 2 == 1) two = (H - 1 + W - 1) / 2;
		else two = (H % 2 == 0 ? H : W) / 2;
	}
	int one = (H % 2 == 1 && W % 2 == 1);

	map<char, int> Nums;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			char c;
			cin >> c;
			Nums[c]++;
		}
	}
	bool ans = true;
	for (auto& p : Nums) {
		while (p.second >= 4 && four>0) {
			p.second -= 4;
			four--;
		}
		while (p.second >= 2 && two > 0) {
			p.second -= 2;
			two--;
		}
		if (p.second == 1 && one == 1) {
			p.second = 0;
			one = 0;
		}
		if (p.second > 0) {
			ans = false;
			break;
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
}