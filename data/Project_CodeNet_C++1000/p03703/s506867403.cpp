#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()
const ll MOD = 1000000007;

int X[524288];

ll RSQ(int s, int t, int k = 1, int l = 0, int r = 262143) {
	if (t < l || r < s)return 0;
	if (s <= l && r <= t) {
		return X[k];
	}
	ll lv = RSQ(s, t, k * 2, l, (l + r) / 2);
	ll rv = RSQ(s, t, k * 2 + 1, (l + r) / 2 + 1, r);
	return lv + rv;
}

void upd(int x, int v = 0) {
	x += 262144;
	X[x] = v;
	while (x > 1) {
		x /= 2;
		X[x] = X[x * 2] + X[x * 2 + 1];
	}
}

int main() {
	ll N, K, Y;
	cin >> N >> K;
	vector<pair<ll, ll>> A(N + 1);
	vector<ll> C(N + 1, 0), B = C;
	for (int i = 1;i <= N;i++) {
		cin >> Y;
		B[i] = Y - K;
		B[i] += B[i - 1];
		A[i] = { B[i],i };
		upd(i, 1);
	}
	sort(all(A));
	for (int i = 0;i <= N;i++) {
		C[A[i].second] = i;
	}
	ll ans = 0;
	for (int i = 0;i <= N;i++) {
		ans += RSQ(C[i] + 1, N);
		upd(C[i]);
	}
	cout << ans << endl;
}