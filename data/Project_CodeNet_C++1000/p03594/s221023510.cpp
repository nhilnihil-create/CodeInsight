#include <iostream>
#include <algorithm>
using namespace std;

int h, w, d;
char s[] = { 'R', 'Y', 'G', 'B' }, c[500][500];

int main() {
	cin >> h >> w >> d;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int y = i + j;
			int x = i - j + (h + w);
			int color = y / d % 2 * 2 + x / d % 2;
			c[i][j] = s[color];
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << c[i][j];
		}
		cout << endl;
	}
}