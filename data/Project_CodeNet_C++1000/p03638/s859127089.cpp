#include <iostream>
#include <vector>
using namespace std;
int main() {
	int H, W, N;
	cin >> H >> W >> N;
	vector<int> a(N);
	for (auto& i : a) cin >> i;
	vector<vector<int>> c(H, vector<int>(W));
	for (int i = 0, h = 0, w = 0, x = 1; i < H * W; i++) {
		c[h][w] = x;
		a[x - 1]--;
		if (a[x - 1] == 0) x++;
		if (w % 2 == 0) {
			if (h == H - 1) w++;
			else h++;
		}
		else {
			if (h == 0) w++;
			else h--;
		}
	}
	for (const auto& v : c) {
		for (const auto& i : v) cout << i << " ";
		cout << endl;
	}
}
