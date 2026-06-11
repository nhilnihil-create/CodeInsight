#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
int l[300000], r[300000];
vector<int> v[100001];
struct BIT {
	vector<ll> bit;
	int n;
	BIT(int n) :n(n) {
		bit = vector<ll>(n + 1, 0);
	}
	ll sum(int i) {
		i++;
		ll s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	ll get(int i) {
		ll ret = sum(i);
		if (i > 0) ret -= sum(i - 1);
		return ret;
	}
	void add(int i, ll x) {
		i++;
		while (i <= n) {
			bit[i] += x;
			i += i & -i;
		}
	}
};
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> l[i] >> r[i];
		v[r[i] - l[i] + 1].push_back(i);
	}
	cout << N << endl;
	int sum = N;
	BIT bit(M + 2);
	for (int i = 2; i <= M; i++) {
		sum -= v[i - 1].size();
		for (int j : v[i - 1]) {
			bit.add(l[j], 1);
			bit.add(r[j] + 1, -1);
		}
		int ans = sum;
		for (int j = i; j <= M; j += i) {
			ans += bit.sum(j);
		}
		cout << ans << endl;
	}
}
