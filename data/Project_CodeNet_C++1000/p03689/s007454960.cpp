#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <tuple>
#include <functional>
using namespace std;

long long H, W, h, w, A[1009][1009];

int main() {
	cin >> H >> W >> h >> w;
	if (H%h == 0 && W%w == 0) {
		cout << "No" << endl;
		return 0;
	}
	long long K = h * w - 1;
	long long E = 999999999LL / K;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (i%h == 0 && j%w == 0) A[i][j] = -1LL * (E * K + 1);
			else A[i][j] = E;
		}
	}
	cout << "Yes" << endl;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (j) cout << " "; cout << A[i][j];
		}
		cout << endl;
	}
	return 0;
}