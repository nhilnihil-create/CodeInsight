#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
ll sum[200000];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> sum[i];
		if (i > 0) sum[i] += sum[i - 1];
	}
	ll ans = INF;
	for (int i = 0; i + 1 < N; i++) {
		ll A = sum[i];
		ll B = sum[N - 1] - sum[i];
		ans = min(ans, abs(A - B));
	}
	cout << ans << endl;
 }