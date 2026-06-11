#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()
#define MOD 1000000007

ll gcd(ll x, ll y) {
	while (y) {
		x %= y;
		swap(x, y);
	}
	return x;
}

ll lcm(ll x, ll y) {
	return x / gcd(x, y) * y;
}

int main() {
	ll N, A, T;
	cin >> N;
	vector<ll> As(N), Ts(N);
	for (int i = 0;i < N;i++)cin >> As[i] >> Ts[i];

	ll ng = 0, ok = (1LL << 61), mid, x, y, a, b;
	while (ng + 1 != ok) {
		mid = (ok + ng) / 2;

		x = mid / (As[N - 1] + Ts[N - 1]);
		a = x * As[N - 1];
		b = x * (Ts[N - 1]);
		for (int i = N - 2;i >= 0;i--) {
			x = a / As[i];
			y = b / Ts[i];
			x = min(x, y);
			a = As[i] * x;
			b = Ts[i] * x;
		}
		if (a != 0 && b != 0)
			ok = mid;
		else
			ng = mid;
	}
	cout << ok << endl;
}