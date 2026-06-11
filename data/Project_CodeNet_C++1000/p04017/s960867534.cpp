#include <bits/stdc++.h>
using namespace std;

const int N = 110000;
const int L = 32;

int a[N];
int nxt[N][L];

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int LL; cin >> LL;
	for (int i = 1; i <= n; i++) nxt[i][0] = upper_bound(a + 1, a + n + 1, a[i] + LL) - a - 1;
	for (int j = 1; j < L; j++) {
		for (int i = 1; i <= n; i++) nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
	}
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		if (l > r) swap(l, r);
		long long ans = 0;
		for (int i = L - 1; i >= 0; i--) {
			if (nxt[l][i] < r) ans += 1LL << i, l = nxt[l][i];
		}
		cout << ans + 1 << "\n";
	}
	
	return 0;
}
