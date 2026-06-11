#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 111;

int a[N];

int sq(int x) {
	return x * x;
}

int32_t main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, ans = 0x3f3f3f3f; cin >> n;

	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = -1000; i <= +1000; i++) {
		int t = 0;
		for(int j = 1; j <= n; j++) {
			t += sq(a[j] - i);
		}
		ans = min(ans, t);
	}
	cout << ans << endl;
}