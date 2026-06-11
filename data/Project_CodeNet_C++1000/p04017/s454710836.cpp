#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = (int)a; i <= (int)b; i++)

int n, arr[100050], l, q, a, b, p[100050][20];

int main() {
  	ios_base::sync_with_stdio(0);
  	cin.tie(0);
	cin >> n;
	FOR(i, 1, n) cin >> arr[i];
	cin >> l >> q;
	FOR(i, 1, n-1) p[i][0] = upper_bound(arr+1, arr+n+1, arr[i]+l) - arr - 1;
	p[n][0] = -1;
	FOR(k, 1, 17) {
		FOR(i, 1, n) {
			if (p[i][k-1] != -1) p[i][k] = p[p[i][k-1]][k-1];
			else p[i][k] = -1;
		}
	}
	while (q--) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		int ans = 0;
		for(int k = 17; k >= 0; k--) {
			if (p[a][k] == -1) continue;
			if (p[a][k] <= b) {
				a = p[a][k];
				ans += (1<<k);
			}
		}
		if (a != b) ans++;
		cout << ans << "\n";
	}
}
