#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int w, h, n; cin >> w >> h >> n;
	int upper = h;
	int	lower = 0;
	int	left = 0;
	int right = w;
	for (int i = 0; i < n; i++) {
		int x, y, a; cin >> x >> y >> a;
		if (a == 1) {
			left = max(left, x);
		}
		else if (a == 2) {
			right = min(right, x);
		}
		else  if (a == 3) {
			lower = max(lower, y);
		}
		else { // a == 4
			upper = min(upper, y);
		}
	}
	cout << max(0, right - left) * max(0, upper - lower) << endl;
	return 0;
}