#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
#include <iomanip>
using namespace std;
typedef long long int ll;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, a[200010], t = 0, h;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i != n - 1)t += a[i];
		else h = a[i];
	}
	ll ans = abs(t - h);
	for (int i = n - 2; i > 0; i--) {
		h += a[i];
		t -= a[i];
		ans = min(ans, abs(t - h));
	}
	cout << ans << endl;
	return 0;
}
