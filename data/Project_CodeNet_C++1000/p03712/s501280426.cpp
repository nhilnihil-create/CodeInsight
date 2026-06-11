#include <iostream>
#include <vector>
using namespace std;
int main() {
	int H, W;
	cin >> H >> W;

	vector<vector<char>> pic(H + 2, vector<char>(W + 2));

	for (int i = 1; i < H+1; i++) {
		for (int j = 1; j < W+1; j++) {
			cin >> pic.at(i).at(j);
		}
	}

	for (int k = 0; k < W+1; k++) {
		pic.at(0).at(k) = '#';
	}

	for (int l = 0; l < W+1; l++) {
		pic.at(H + 1).at(l) = '#';
	}

	for (int m = 0; m < H + 2; m++) {
		pic.at(m).at(0) = '#';
		pic.at(m).at(W + 1) = '#';
	}

	for (int n = 0; n < H + 2; n++) {
		if (n > 0) cout << endl;
		for (int o = 0; o < W + 2; o++) {
			cout << pic.at(n).at(o);
		}
	}
}