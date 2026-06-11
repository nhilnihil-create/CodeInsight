
// D - Walk and Teleport

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll X[100000];

int main() {
	ll N, A, B;
	cin >> N >> A >> B;

	for (int i=0; i<N; i++) {
		cin >> X[i];
	}

	ll ans = 0;
	for (int i=0; i<N-1; i++) {
		ans += min((X[i+1] - X[i]) * A, B);
	}

	cout << ans << endl;

	return 0;
}