#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;

int cnt[10000];
int int_map[100][100];
int main() {
	cin >> H >> W >> N;
	rep(i, N) {
		cin >> cnt[i];
	}
	int index = 0;
	rep(i, H) {
		int j = (i % 2 == 0 ? 0 : W - 1);
		for (;;) {
			if ((i % 2 == 0 && j == W) || (i % 2 == 1 && j == -1)) break;
			int_map[i][j] = (index + 1);
			cnt[index]--;
			if (cnt[index] == 0) index++;
			j += (i % 2 == 0 ? 1 : -1);
		}
	}

	rep(i, H) {
		rep(j, W) {
			cout << int_map[i][j] << " ";
		}
        cout << endl;
	}
}
