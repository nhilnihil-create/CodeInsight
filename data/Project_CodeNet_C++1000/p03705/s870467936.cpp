
// A - A+...+B Problem

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	ll N, A, B;
	cin >> N >> A >> B;

	if (A > B || (N == 1 && A != B)) {
		cout << 0 << endl;
		return 0;
	}

	ll min_s = A + (N-2) * A + B;
	ll max_s = A + (N-2) * B + B;

	ll ans = max_s - min_s + 1;

	cout << ans << endl;

	return 0;
}