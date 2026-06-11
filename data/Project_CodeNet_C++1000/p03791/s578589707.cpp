#include <bits/stdc++.h>
using namespace std;

const int N = 200005, mo = 1000000007;

typedef long long LL;
int n;
int a[N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	int d = 0, p = 0;
	LL ans = 1;
	for (int i = 1; i <= n; ++i){
		d = max(i - ((a[i - 1] + 1) >> 1) - 1, d);
		(ans *= 1ll * (i - d)) %= mo;
	}
	cout << ans << endl;
	return 0;
}
