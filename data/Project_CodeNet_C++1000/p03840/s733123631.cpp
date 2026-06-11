#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	vector<Int> a(7);
	for (int i = 0; i < 7; ++i) { cin >> a[i]; }

	Int ans = 2*(a[0]/2 + a[3]/2 + a[4]/2) + 3*((a[0]&1) && (a[3]&1) && (a[4]&1));
	if (a[0] && a[3] && a[4]) {
		ans = max(ans, 2*((a[0]-1)/2 + (a[3]-1)/2 + (a[4]-1)/2) + 3);
	}
	cout << ans + a[1] << "\n";

	return 0;
}
