#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
typedef pair<ll, int> P;
ll X[100000];
int W[100000];
ll ans[100000];
ll N, L, T;
int get_num(int k) {
	ll cnt = 0;
	for (int i = 0; i < N; i++) {
		if (W[k] == W[i]) continue;
		double t = 0;
		if (W[k] == 1) {
			if (X[i] > X[k]) t = (X[i] - X[k]) / 2.0;
			else t = (X[i] + L - X[k]) / 2.0;
		}
		else {
			if (X[i] > X[k]) t = (L - X[i] + X[k]) / 2.0;
			else t = (X[k] - X[i]) / 2.0;
		}
		if (T < t) continue;
		(cnt += (ll)((T - t) / (L / 2.0)) + 1) %= N;
	}
	ll ret = k;
	if (W[k] == 1) (ret += cnt) %= N;
	else (ret += N - cnt) %= N;
	return ret;
}
int main() {
	cin >> N >> L >> T;
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> W[i];
	}
	vector<P> pos;
	for (int i = 0; i < N; i++) {
		if (W[i] == 1) pos.emplace_back((X[i] + T) % L, i);
		else pos.emplace_back((X[i] + (L - T % L)) % L, i);
	}
	sort(pos.begin(), pos.end());
	int idx = get_num(pos[0].second);
	ans[idx] = pos[0].first;
	for (int i = 1; i < N; i++) {
		if (pos[i].first == pos[0].first) {
			if (W[pos[0].second] == 1) {
				ans[(idx + N - 1) % N] = pos[0].first;
			}
			else {
				(idx += 1) %= N;
				ans[idx] = pos[i].first;
			}
		}
		else {
			(idx += 1) %= N;
			ans[idx] = pos[i].first;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << endl;
	}
}
