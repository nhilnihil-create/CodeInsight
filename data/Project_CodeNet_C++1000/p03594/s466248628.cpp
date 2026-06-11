#include <bits/stdc++.h>
using namespace std;

const char Col[2][2] = { { 'R','Y' },{ 'G','B' } };
int H, W, d;

char get_col(int x, int y) {
	int i = (x / d) % 2;
	int j = (y / d) % 2;
	return Col[i][j];
}

int main() {

	ios::sync_with_stdio(false);
    cin.tie(0);
	cin >> H >> W >> d;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			int x = i + j;
			int y = j - i + H;
//			cout << j <<" "<< i << "----";
//			cout << y <<" "<< x << endl;
			char c = get_col(x, y);
			cout << c;
			if (j == W - 1)
				cout << '\n';
		}
	}
	return 0;
}
