#include <bits/stdc++.h>
using namespace std;

const int maxn = 110000;

int a[maxn];
int nxt[maxn][20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, l, q; cin >> n;
	for(int i = 1; i <= n; ++ i) cin >> a[i];
	cin >> l;
	for(int i = 1; i <= n; ++ i) {
		int nx = upper_bound(a + i, a + n + 1, a[i] + l) - a;
		nxt[i][0] = nx - 1;
	}
	for(int j = 1; j < 20; ++ j) for(int i = 1; i <= n; ++ i)
		nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
	cin >> q;
	while(q --) {
		int a, b; cin >> a >> b;
		if(a > b) swap(a, b);
		int ans = 0;
		while(a != b) {
			int j = 0, f = 0;
			for(j = 0; j < 20; ++ j) {
				if(nxt[a][j] >= b) {
					if(j == 0) {
						ans ++;
						f = 1;
						break;
					} else {
						-- j;
						a = nxt[a][j];
						ans += 1 << j;
						break;
					}
				}
			}
			if(f) break;
		}
		cout << ans << "\n";
	}
	return 0;
}
