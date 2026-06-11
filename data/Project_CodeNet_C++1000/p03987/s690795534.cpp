//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2 * 100 * 1000 + 17;

ll n, a[MAXN], p[MAXN], ans;
set<ll> s;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], p[a[i]] = i;
	s.insert(0);
	s.insert(n + 1);
	for (int i = 1; i <= n; i++) {
		auto t = s.lower_bound(p[i]);
		auto tp = t;
		tp--;
		ans += (*t - p[i]) * (p[i] - *tp) * i;
		s.insert(p[i]);
	}
	cout << ans << endl;
	return 0;
}
