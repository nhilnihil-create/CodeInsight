#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;

	string ans = "";
	int tmp;

	tmp = ty - sy;
	while (tmp--) {
		ans += "U";
	}
	tmp = tx - sx;
	while (tmp--) {
		ans += "R";
	}
	tmp = ty - sy;
	while (tmp--) {
		ans += "D";
	}
	tmp = tx - sx;
	while (tmp--) {
		ans += "L";
	}

	ans += "L";
	tmp = ty - sy + 1;
	while (tmp--) {
		ans += "U";
	}
	tmp = tx - sx + 1;
	while (tmp--) {
		ans += "R";
	}
	ans += "D";
	ans += "R";
	tmp = ty - sy + 1;
	while (tmp--) {
		ans += "D";
	}
	tmp = tx - sx + 1;
	while (tmp--) {
		ans += "L";
	}
	ans += "U";

	cout << ans << endl;
	return 0;
}