#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
ll h[100000];
int main() {
	int N, A, B;
	cin >> N >> A >> B;
	for (int i = 0; i < N; i++) {
		cin >> h[i];
	}
	ll l = 0, r = 1 << 30;
	while ((r - l) > 1) {
		ll m = (l + r) / 2;
		ll cnt = 0;
		for (int i = 0; i < N; i++) {
			if (m*B < h[i]) {
				cnt += (h[i] - m * B + (A - B) - 1) / (A - B);
			}
		}
		if (cnt <= m) r = m;
		else l = m;
	}
	cout << r << endl;
 }