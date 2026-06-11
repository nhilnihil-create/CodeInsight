#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int a[n], vis[(n+1)/2];
	memset(vis, 0, sizeof(vis));
	for (int i=0; i<n; i++) {
		cin >> a[i];
		if (n%2 == a[i]%2) {
			cout << 0; return 0;
		}
		if (++vis[a[i]/2] > 2) {
			cout << 0; return 0;
		}
	}
	if ((n&1) && vis[0] != 1) {
		cout << 0; return 0;
	}
	int ans = 1;
	for (int i=0; i<n/2; i++) {
		ans = (ans*1ll*2) % MOD;
	}
	cout << ans;
}