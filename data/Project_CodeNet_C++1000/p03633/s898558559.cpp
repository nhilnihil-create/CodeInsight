#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = INT_MAX / 2;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	int N; cin >> N;
	vector<ll> a(N);
	rep(i, N) cin >> a[i];
	ll m = a[0];
	rep(i, N) m = lcm(m, a[i]);
	cout << m << endl;
}
