#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <array>
#include <vector>
#include <utility>
#include <bitset>
#include <queue>
#include <unordered_set>

using namespace std;

typedef long long ll;
constexpr ll MAX_N = 300;
constexpr ll INF = 1e18;
ll N;
ll D[MAX_N][MAX_N];
ll W[MAX_N][MAX_N];

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            cin >> D[i][j];
            W[i][j] = D[i][j];
        }
    }

    for (ll k = 0; k < N; k++) {
        for (ll i = 0; i < N; i++) {
            for (ll j = 0; j < N; j++) {
                W[i][j] = min(W[i][j], W[i][k] + W[k][j]);
            }
        }
    }

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            if (D[i][j] != W[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    ll ans = 0;

    for (ll i = 0; i < N; i++) {
        for (ll j = i + 1; j < N; j++) {
            bool need = true;
            for (ll k = 0; k < N; k++) {
                if (i == k || j == k) {
                    continue;
                }

                if (W[i][j] == W[i][k] + W[k][j]) {
                    need = false;
                    break;
                }
            }

            if (need) {
                ans += W[i][j];
            }
        }
    }

    cout << ans << endl;
}

