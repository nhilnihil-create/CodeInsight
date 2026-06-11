
// A - Getting Difference

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll get_gcd(ll x, ll y) {
	if (y > 0) return get_gcd(y, x % y);
	else return x;
}

int A[100000];

int main() {
	int N, K;
	cin >> N >> K;

	int max_A = 0;
	for (int i=0; i<N; i++) {
		cin >> A[i];
		max_A = max(max_A, A[i]);
	}

	int gcd = A[0];
	for (int i=0; i<N; i++) {
		gcd = get_gcd(gcd, A[i]);
	}

	string ans;
	if (K <= max_A && K % gcd == 0) ans = "POSSIBLE";
	else ans = "IMPOSSIBLE";

	cout << ans << endl;

	return 0;
}