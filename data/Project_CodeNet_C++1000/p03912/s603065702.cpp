#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5+5;

int n, m;
set<int> odd[MAXN];
int ct[MAXN];
int ctm[MAXN];
set<int> o;

int l;
int ans = 0;

int main() {
	cin >> n >> m;
	l = n;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		ct[x]++;
		ctm[x%m]++;
	}

	for (int i = 0; i <= m/2; ++i) {
		if (i == 0 || (2*i == m)) {
			ans += ctm[i]/2;
			continue;
		}

		//pair i, m-i
		int oi = 0;
		int omi = 0;
		for (int j = i; j <= 100000; j += m)
			oi += (ct[j]%2 == 1);
		for (int j = m-i; j <= 100000; j += m)
			omi += (ct[j]%2 == 1);

		// cout << i << ' ' << oi << ' ' << omi << endl;

		int ops = min(ctm[i], ctm[m-i]);
		int waste = max(0, oi-ops) + max(0, omi-ops);

		// cout << i << ' ' << oi << ' ' << omi << ' ' << ops << ' ' << waste << endl;
		ans += (ctm[i] + ctm[m-i] - waste)/2;
	}

	cout << ans << endl;
}