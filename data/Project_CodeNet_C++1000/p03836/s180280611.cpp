#include<bits/stdc++.h>

using namespace std;

int main() {

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	const int dx = tx - sx, dy = ty - sy;
	cout << string(dy, 'U') << string(dx, 'R') << string(dy, 'D') << string(dx, 'L');
	cout << 'L' << string(dy + 1, 'U') << string(dx + 1, 'R') << 'D';
	cout << 'R' << string(dy + 1, 'D') << string(dx + 1, 'L') << 'U';
	cout << '\n';
	return 0;
}