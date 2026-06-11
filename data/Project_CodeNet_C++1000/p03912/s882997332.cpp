#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 100100
int n, m;
int a[N];
int b[N];
int c[N];
int d[N];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[a[i]%m]++;
		c[a[i]] ++;
	}
	int S = 0;
	S += b[0]/2;
	if (m >= 2) {
		int u = m/2;
		if (m%2 == 0) {
			S += b[u]/2;
		} else {
			u ++;
		}
		for (int i = 1; i < u; i ++) {
			int T = min(b[i], b[m-i]);
			S += T;
			d[i] = T;
			d[m-i] = T;
		}
		for (int i = 1; i < m; i++) if (i*2 != m && b[i] > d[i]) {
			int odd = 0;
			for (int j = i; j < N; j += m) {
				if (c[j]&1) odd++;
			}
			if (d[i] >= odd) {
				S += (b[i]-d[i])/2;
			} else {
				S += (b[i]-odd)/2;
			}
		}
	}
	cout << S << endl;
	return 0;
}