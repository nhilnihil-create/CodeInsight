#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
ll A[100000];
ll maxA[100000];
int main() {
	int N, T;
	cin >> N >> T;
	for (int i = 0; i < N; i++) cin >> A[i];
	maxA[N - 1] = A[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		maxA[i] = max(maxA[i + 1], A[i]);
	}
	ll now = 0;
	for (int i = 0; i + 1 < N; i++) {
		now = max(maxA[i + 1] - A[i], now);
	}
	int ans = 0;
	for (int i = 0; i + 1 < N; i++) {
		if (maxA[i + 1] - A[i] == now) {
			ans++;
		}
	}
	cout << ans << endl;
}
