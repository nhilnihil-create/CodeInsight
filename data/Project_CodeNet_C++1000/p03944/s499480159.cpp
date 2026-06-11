#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int x_right, y_upper, n; cin >> x_right >> y_upper >> n;
	int x_left = 0;
	int y_lower = 0;
	for (int i = 0; i < n; i++) {
		int x, y, a; cin >> x >> y >> a;
		if (a == 1) x_left = max(x_left, x);
		if (a == 2) x_right = min(x_right, x);
		if (a == 3) y_lower = max(y_lower, y);
		if (a == 4) y_upper = min(y_upper, y);
	}
	cout << max(0, x_right - x_left) * max(0, y_upper - y_lower) << endl;
    return 0;
}