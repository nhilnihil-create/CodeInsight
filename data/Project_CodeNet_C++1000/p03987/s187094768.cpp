#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define add push_back
#define f first
#define s second
#define pw(x) (1ll << (x))
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
const ll INF = (ll)1e9 + 2019;

const int N = 2e5 + 10;
int arr[N], t[N * 4], nl[N], nr[N];

int query(int v, int l, int r, int a, int b) {
	if (a > r || l > b) {
		return -INF;
	}
	if (a <= l && r <= b) {
		return t[v];
	}
	int m = (l + r) / 2;
	return max(query(v * 2, l, m, a, b), query(v * 2 + 1, m + 1, r, a, b));
}

void update(int v, int l, int r, int p, int x) {
	if (l == r) {
		t[v] = x;
		return;
	}
	int m = (l + r) / 2;
	if (p <= m) {
		update(v * 2, l, m, p, x);
	} else {
		update(v * 2 + 1, m + 1, r, p, x);
	}
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}

void mane() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	memset(t, -1, sizeof(t));
	for (int i = 0; i < n; i++) {
		nl[i] = query(1, 0, n, 0, arr[i] - 1);
		update(1, 0, n, arr[i], i);
	}
	for (int i = 0; i < N * 4; i++) {
		t[i] = -n;
	}
	for (int i = n - 1; i >= 0; i--) {
		nr[i] = -query(1, 0, n, 0, arr[i] - 1);
		update(1, 0, n, arr[i], -i);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (ll)arr[i] * (i - nl[i]) * (nr[i] - i);
		//cerr << i << " " << nl[i] << " " << nr[i] << endl;
	}
	cout << ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	mane();
#ifdef flaax
	cout << endl; cerr << endl << "\t" << fixed << setprecision(12) << (ld)clock() / CLOCKS_PER_SEC << " sec" << endl;
#endif
}