#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
	string ans = "";
	int u1 = ty - sy;
	int r1 = tx - sx;
	int tmp_u1;
	int tmp_r1;
	tmp_u1 = u1;
	tmp_r1 = r1;
	while (tmp_u1--) {
		ans += "U";
	}
	while (tmp_r1--) {
		ans += "R";
	}
	tmp_u1 = u1;
	tmp_r1 = r1;
	while (tmp_u1--) {
		ans += "D";
	}
	while (tmp_r1--) {
		ans += "L";
	}
	int l2 = 1;
	int u2 = u1 + 1;
	int r2 = r1 + 1;
	int d2 = 1;
	int tmp_l2;
	int tmp_u2;
	int tmp_r2;
	int tmp_d2;
	tmp_l2 = l2;
	tmp_u2 = u2;
	tmp_r2 = r2;
	tmp_d2 = d2;
	while (tmp_l2--) {
		ans += "L";
	}
	while (tmp_u2--) {
		ans += "U";
	}
	while (tmp_r2--) {
		ans += "R";
	}
	while (tmp_d2--) {
		ans += "D";
	}
	tmp_l2 = l2;
	tmp_u2 = u2;
	tmp_r2 = r2;
	tmp_d2 = d2;
	while (tmp_l2--) {
		ans += "R";
	}
	while (tmp_u2--) {
		ans += "D";
	}
	while (tmp_r2--) {
		ans += "L";
	}
	while (tmp_d2--) {
		ans += "U";
	}
	cout << ans << endl;
	return 0;
}