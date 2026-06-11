#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main() {
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;

	string r1, r2, r3, r4;
	for (int i = 0; i < ty - sy; i++) {
		r1.push_back('U');
	}
	for (int i = 0; i < tx - sx; i++) {
		r1.push_back('R');
	}

	r3.push_back('L');
	for (int i = 0; i < ty - sy + 1; i++) {
		r3.push_back('U');
	}
	for (int i = 0; i < tx - sx + 1; i++) {
		r3.push_back('R');
	}
	r3.push_back('D');

	for (int i = 0; i < r1.size(); i++) {
		if (r1.at(i) == 'U') {
			r2.push_back('D');
		}
		if (r1.at(i) == 'R') {
			r2.push_back('L');
		}
	}
	for (int i = 0; i < r3.size(); i++) {
		if (r3.at(i) == 'U') r4.push_back('D');
		if (r3.at(i) == 'L') r4.push_back('R');
		if (r3.at(i) == 'D') r4.push_back('U');
		if (r3.at(i) == 'R') r4.push_back('L');
	}

	cout << r1 << r2 << r3 << r4 << endl;
}