#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int w, h, n; cin >> w >> h >> n;
	int w_right = w;
	int w_left = 0;
	int h_upper = h;
	int h_lower = 0;
	for (int i = 0; i < n; i++) {
		int x, y, a; cin >> x >> y >> a;
		if (a == 1) w_left = max(w_left, x);
		if (a == 2) w_right = min(w_right, x);
		if (a == 3) h_lower = max(h_lower, y);
		if (a == 4) h_upper = min(h_upper, y);
	}
	cout << max(0, w_right - w_left) * max(0, h_upper - h_lower) << endl;
	return 0;
}