#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;

set<int> x;
set<int> y;
int main() {
	cin >> A >> B >> C >> D >> E >> F;
	for (int i = 0; A * i * 100 <= F; i++) {
		for (int j = 0; (A * i + B * j) * 100 <= F; j++) {
			x.insert(A * i + B * j);
		}
	}
	for (int i = 0; C * i <= F; i++) {
		for (int j = 0; C * i + D * j <= F; j++) {
			y.insert(C * i + D * j);
		}
	}
	double max_con = 0;
	Pa ans = Pa(0, 0);
	for (auto i = x.begin(); i != x.end(); i++) {
		for (auto j = y.begin(); j != y.end(); j++) {
			double con = 1. * (*j) / ((*i) * 100 + *j);
			if (con > 1. * E / (E + 100) || ((*i) * 100 + *j) > F) continue;
			if (max_con <= con) {
				max_con = con;
				ans = Pa((*i) * 100 + *j, *j);
			}
		}
	}
	cout << ans.first << " " << ans.second;
}
