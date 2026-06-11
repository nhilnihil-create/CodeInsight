#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll ns, nc; cin >> ns >> nc;
	if (nc % 2 == 1) nc--;
	
	ll ans = 0;

	if (2* ns == nc) {
		ans += ns;
	}
	else if (2 * ns < nc) {
		ans += ns;
		nc -= 2 * ns;
		ans += nc / 4;
	}
	else { // 2 * ns > nc
		ans += nc / 2;
	}

	cout << ans << endl;
	return 0;
}