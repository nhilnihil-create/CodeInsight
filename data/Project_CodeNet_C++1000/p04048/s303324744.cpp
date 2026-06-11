#include<bits/stdc++.h>
#define int long long
#define puts(x) cout << x << "\n"
using namespace std;
signed main() {
	int x, n, ans = 0; cin >> n >> x;
	n -= x;
	while (1) {
		if (n < x)swap(n, x);
		if (x == 0)break;
		ans += (n - n % x) * 3; n %= x;
	}
	puts(ans);
}