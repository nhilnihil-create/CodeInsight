#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1<<20, mod = 924844033;
int c[maxn], r[maxn], n, m;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) c[i] = 1;
	r[1] = 1;
	for(int x, y, i = 0; i < m; i++) {
		cin >> x >> y;
		r[y] |= r[x];
		if(--c[x] == 0) {
			r[x] = 0;
		}
		c[y]++;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) ans += r[i];
	cout << ans;
}
