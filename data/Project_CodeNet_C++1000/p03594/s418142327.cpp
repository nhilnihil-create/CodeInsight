#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int h, w, d;
char col[1100][505];

int main() {
	cin >> h >> w >> d;
	if (d%2 == 1) {
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if ((i+j)%2 == 0)
					cout << "R";
				else
					cout << "G";
			}
			cout << "\n";
		}
		return 0;
	}

	int k = d/2;
	for (int i = 0; i < h + w; i += d) {
		if ((i/d)%2 == 0) {
			for (int j = 0; j < d; ++j) {
				//color first j ones B
				int p = d-j/2;
				for (int n = 0; n < min(h+w-i-j, w); n++) {
					if (n%d >= p || n%d <= (p+k+d-1)%d)
						col[i+j+n][n] = 'Y';
					else
						col[i+j+n][n] = 'B';
				}
			}
		} else {
			for (int j = 0; j < d; ++j) {
				//color first j ones B
				int p = d-j/2;
				for (int n = 0; n < min(h+w-i-j, w); n++) {
					if (n%d >= p || n%d <= (p+k+d-1)%d)
						col[i+j+n][n] = 'R';
					else
						col[i+j+n][n] = 'G';
				}
			}
		}
	}

	for (int i = w; i < h+w; ++i) {
		for (int j = 0; j < w; ++j)
			cout << col[i][j];
		cout << "\n";
	}
}
