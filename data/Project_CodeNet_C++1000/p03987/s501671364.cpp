#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(x) ((int) x.size())
#define all(x) (x).begin(), (x).end()
#define re return
#define mp make_pair
#define makeunique(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())
#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<string> vs;

template <class T> T abs (T x) { re x > 0 ? x : -x; }
template <class T> T sqr (T x) { re x * x; }

const double pi = acos(-1.);
const ll inf = 1e18 + 7;
const int N = 3e5 + 17;

int n, m;
int a[N], x[N], y[N];
int t[2 * N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < 2 * N; i++) t[i] = -1;
	for (int i = 0; i < n; i++) {
		int l = 0;
		int r = a[i];
		x[i] = -1;
		for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) x[i] = max(x[i], t[l++]);
			if (!(r & 1)) x[i] = max(x[i], t[r--]);
		}
		x[i]++;
		int pos = a[i] + n;
		t[pos] = i;
		while (pos > 1) {
			t[pos >> 1] = max(t[pos], t[pos ^ 1]);
			pos >>= 1;
		}
	}
	ll ans = 0;
	for (int i = 0; i < 2 * N; i++) t[i] = n;
	for (int i = n - 1; i >= 0; i--) {
		int l = 0;
		int r = a[i];
		y[i] = n;
		for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) y[i] = min(y[i], t[l++]);
			if (!(r & 1)) y[i] = min(y[i], t[r--]);
		}
		y[i]--;
		int pos = a[i] + n;
		t[pos] = i;
		while (pos > 1) {
			t[pos >> 1] = min(t[pos], t[pos ^ 1]);
			pos >>= 1;
		}
		ll cntl = i - x[i] + 1, cntr = y[i] - i + 1;
		ans += cntl * cntr * (a[i] + 1);
	}
	cout << ans;
}
