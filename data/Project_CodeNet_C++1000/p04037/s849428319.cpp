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
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &it : a) {
		cin >> it;
	}
	sort(a.rbegin(), a.rend());
	pair<int, int> cur = {1, 0};
	while (cur.S + 1 < n && a[cur.S + 1] >= cur.F + 1) {
		cur.F++;
		cur.S++;
	}
	int cnt = 0;
	for (int i = cur.S; i < n; i++) {
		if (a[i] >= cur.F) {
			cnt++;
		}
	}
	if (cnt % 2 == 0 || (a[cur.S] - cur.F + 1) % 2 == 0) {
		cout << "First\n";
	}
	else {
		cout << "Second\n";
	}
}	