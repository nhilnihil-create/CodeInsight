#include <iostream>
#define int long long
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

int n;
int a[100000];

signed main() {
	int i;
	
	cin >> n;
	rep(i, n) cin >> a[i];
	
	int ans = 0;
	for (i = 0; i + 1 < n; i++) {
		if (a[i] % 2 == 0) {
			ans += a[i] / 2;
		}
		else if (a[i + 1] == 0) {
			ans += a[i] / 2;
		}
		else {
			a[i]--;
			a[i + 1]--;
			ans++;
			ans += a[i] / 2;
		}
	}
	ans += a[n - 1] / 2;
	
	cout << ans << endl;
	return 0;
}