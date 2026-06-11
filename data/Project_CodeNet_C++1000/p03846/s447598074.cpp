#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;

map<int, int> cnt;
int main() {
	cin >> N;
	bool flag = false;
	rep(i, N) {
		cin >> A;
		if (cnt.find(A) == cnt.end()) cnt[A] = 1;
		else cnt[A]++;
	}
	ll ind = 0;
	for (auto itr = cnt.begin(); itr != cnt.end(); itr++) {
		if (itr->second == 1) {
			if (flag) {
				cout << "0";
				return 0;
			}
			if (N % 2 == 0) {
				cout << "0";
				return 0;
			}
			else {
				if (itr->first != 0) {
					cout << "0";
					return 0;
				}
			}
			flag = true;
		}
		else {
			if (itr->second != 2) {
				cout << "0";
				return 0;
			}
			ind++;
		}
	}
	ll ans = 1;
	rep(i, ind) {
		ans = (ans * 2) % MOD;
	}
	cout << ans;
}

