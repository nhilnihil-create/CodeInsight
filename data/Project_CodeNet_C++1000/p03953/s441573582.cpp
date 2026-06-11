#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 100, LOG = 62;

ll n, m, k, dex, x[N], d[N], is[N], go[N][LOG];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		if(i)
			d[i] = x[i] - x[i - 1], go[i][0] = i;
	}
	cin >> m >> k;
	while(m--) {
		cin >> dex;
		dex--;
		swap(go[dex][0], go[dex + 1][0]);
	}
	for (int j = 1; j < LOG; j++)
		for (int i = 0; i < n; i++)
			go[i][j] = go[go[i][j - 1]][j - 1];
	iota(is, is + n, 0);
	for (int j = LOG - 1; ~j; j--)
		if(k >= (1LL << j)) {
			k -= 1LL << j;
			for (int i = 1; i < n; i++)
				is[i] = go[is[i]][j];
		}
	ll now = x[0];
	cout << now << ' ';
	for (int i = 1; i < n; i++) {
		now += d[is[i]];
		cout << now << ' ';
	}
	return 0;
}