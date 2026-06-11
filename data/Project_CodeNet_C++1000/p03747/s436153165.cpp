#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

int N, T, X, W, l, r;
ll C;
vector<int>R, L;

int main() {
	cin >> N >> C >> T;
	for (int i = 0; i < N; ++i) {
		cin >> X >> W;
		(W == 1 ? R : L).push_back(X);
	}
	if (R.empty()) {
		for (int i = 0; i < N; ++i) {
			cout << (L[i] % C - T%C + C) % C << endl;
		}
	}
	else if (L.empty()) {
		for (int i = 0; i < N; ++i) {
			cout << (R[i] % C + T%C) % C << endl;
		}
	}
	else {
		l = -1;
		r = intmax;
		while (l + 1 != r) {
			int m = (l + r) / 2;
			ll p = C*(m / L.size()) + L[m%L.size()] - R[0];
			if (T * 2 <= p) {
				r = m;
			}
			else {
				l = m;
			}
		}
		vector<int>res;
		for (int i = 0; i < R.size(); ++i) {
			res.push_back((R[i] % C + T%C) % C);
		}
		for (int i = 0; i < L.size(); ++i) {
			res.push_back((L[i] % C - T%C + C) % C);
		}
		sort(res.begin(), res.end());
		int t = (R[0] % C + T%C) % C;
		int k = lower_bound(res.begin(), res.end(), t) - res.begin();
		k = (k - r % N + N) % N;
		for (int i = 0; i < N; ++i) {
			cout << res[(k + i) % N] << endl;
		}
	}
}