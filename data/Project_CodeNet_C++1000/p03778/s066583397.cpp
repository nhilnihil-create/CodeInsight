#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int w, a, b; cin >> w >> a >> b;
	int ans;
	if (a <= b && b <= a + w) {
		ans = 0;
	}
	else if (a <= b + w && b + w <= a) {
		ans = 0;
	}
	else if (a + w < b) {
		ans = b - (a + w);
	}
	else {
		ans = a - (b + w);
	}
	cout << ans << endl;
	return 0;
}