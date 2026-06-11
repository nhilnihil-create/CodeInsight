#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(v) v.begin(),v.end()

const int maxn = 1e5 + 100;
const ll inf = 2e18, mod = 1e9 + 7;

int n, w[maxn], pos;
ll l, t, x[maxn], y[maxn], ans[maxn];

void calcPos() {
	for (int i = 0; i < n; i++) {
		if (w[i] == 1) {
			pos = (pos - ((t + x[i]) / l) % n + n) % n;
		}
		else {
			pos = (pos + ((t - x[i] + l - 1) / l) % n + n) % n;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> l >> t;
	for (int i = 0; i < n; i++) { 
		cin >> x[i] >> w[i];
		y[i] = (x[i] + (w[i] == 1 ? t : -t) % l + l) % l;
	}
	sort(y, y + n);

	calcPos();

	for (int i = 0; i < n; i++) {
		ans[(pos + i) % n] = y[i];
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << endl;
	}
}

