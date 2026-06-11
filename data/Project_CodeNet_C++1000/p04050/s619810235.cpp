#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	vector<int> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		if (a[i] & 1) {
			cnt++;
		}
	}
	if (cnt > 2) {
		cout << "Impossible\n";
		exit(0);
	}
	if (m == 1) {
		if (a[0] == 1) {
			cout << "1\n1\n1\n";
		}
		else {
			cout << a[0] << '\n' << 2 << '\n' << a[0] - 1 << ' ' << 1 << '\n';
		}
		exit(0);
	}
	else {
		vector<int> lol, kek;
		for (int i = 0; i < m; i++) {
			if (a[i] & 1) {
				kek.pb(a[i]);
			}
			else {
				lol.pb(a[i]);
			}
		}
		for (int i = 0; i < SZ(kek); i++) {
			if (i & 1) {
				lol.pb(kek[i]);
			}
			else {
				lol.insert(lol.begin(), kek[i]);
			}
		}
		for (auto it : lol) {
			cout << it << ' ';
		}
		cout << '\n';
		lol[0]--;
		if (lol[0] == 0) {
			lol.erase(lol.begin());
		}
		lol.back()++;
		cout << SZ(lol) << '\n';
		for (auto it : lol) {
			cout << it << ' ';
		}
		cout << '\n';
	}
}