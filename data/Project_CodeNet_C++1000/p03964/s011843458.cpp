#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9+7, MAX = 1e18, larg = 1e5, INF = -1e18;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W, x, y, z;
long long max_value = INF, max_index = -1;
long long min_value = MAX, min_index = -1;
typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else gcd(b, a % b);
}

int main() {
	cin >> N;
	ll curr_a, curr_b;
	cin >> curr_a >> curr_b;
	rep(i, N-1) {
		cin >> A >> B;
		ll inc = max((curr_a - 1) / A + 1, (curr_b - 1) / B + 1);
		curr_a = inc * A;
		curr_b = inc * B;
	}
	cout << curr_a + curr_b;
}
