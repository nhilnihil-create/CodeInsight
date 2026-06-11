#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e18;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W, x, y, z;
long long max_value = INF, max_index = -1;
long long min_value = MAX, min_index = -1;
typedef long long ll;
typedef pair<ll, ll> Pa;

typedef pair<Pa, ll> edge;
vector<edge> edges;
ll range[200][200];
vector<ll> pos;
int main() {
	cin >> N >> M >> R;
	rep(i, R) {
		cin >> A;
		A--;
		pos.push_back(A);
	}
	rep(i, N) {
		rep(j, N) {
			if (i == j) continue;
			range[i][j] = MAX;
		}
	}

	rep(i, M) {
		cin >> A >> B >> C;
		A--; B--;
		range[A][B] = min(range[A][B], C);
		range[B][A] = min(range[B][A], C);
	}
	rep(k, N) {
		rep(i, N) {
			rep(j, N) {
				if (i == j || j == k || k == i) continue;
				range[i][j] = min(range[i][j], range[i][k] + range[k][j]);
			}
		}
	}

	ll ans = MAX;
	sort(pos.begin(), pos.end());
	do {
		ll sum = 0;
		rep(i, R - 1) {
			sum += range[pos[i]][pos[i + 1]];
		}
		ans = min(ans, sum);
	} while (next_permutation(pos.begin(), pos.end()));

	cout << ans;
}