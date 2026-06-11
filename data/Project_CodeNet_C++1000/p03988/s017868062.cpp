#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
const long long inf = 1ll << 61;
typedef pair<int, int> P;
int a[106];
int bucket[106];
signed main() {
	int n; cin >> n;

	rep(i, n)cin >> a[i]; sort(a, a + n);
	rep(i, n)bucket[a[i]]++;
	int mx = a[n - 1], mn = a[0];
	int ans = 0;
	if ((mx + 1) / 2 != mn)ans++;
	if (mx & 1) {
		if (bucket[mn] != 2)ans++;
		for (int i = mn; i <= mx; i++) {
			if (bucket[i] < 2)ans++;
		}
	}
	else {
		if (bucket[mn]!=1)ans++;
		for (int i = mn + 1; i <= mx; i++) {
			if (bucket[i] < 2)ans++;
		}
	}
	if (ans)puts("Impossible");
	else puts("Possible");
}