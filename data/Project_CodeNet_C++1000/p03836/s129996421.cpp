#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int sx, sy, tx, ty, x, y; cin >> sx >> sy >> tx >> ty;

	for (x = sx; x < tx; x++) {
		cout << "R";
	}
	for (y = sy; y < ty; y++) {
		cout << "U";
	}
	for (x = tx; x > sx; x--) {
		cout << "L";
	}
	for (y = ty; y > sy; y--) {
		cout << "D";
	}
	cout << "D";
	for (x = sx; x < tx + 1; x++) {
		cout << "R";
	}
	for (y = sy-1; y < ty; y++) {
		cout << "U";
	}
	cout << "LU";
	for (x = tx; x > sx-1; x--) {
		cout << "L";
	}
	for (y = ty+1; y > sy; y--) {
		cout << "D";
	}
	cout << "R";
	return 0;
}