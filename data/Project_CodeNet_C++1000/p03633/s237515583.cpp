
// C - Multiple Clocks

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll T[100];

ll get_lcm(ll a, ll b) {
	return a / __gcd(a, b) * b;
}

int main() {
	ll N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> T[i];
	}

	ll lcm = 1;

	for (int i=0; i<N; i++) {
		lcm = get_lcm(lcm, T[i]);
	}

	cout << lcm << endl;

	return 0;
}