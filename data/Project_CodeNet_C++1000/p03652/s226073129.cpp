#include"bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> A(N, vector<ll>(M));
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }

    vector<bool> ok(M, true);
    ll ans = INT_MAX;

    for (ll i = 0; i < M; i++) {
        vector<ll> selected_num(M, 0);
        for (ll j = 0; j < N; j++) {
            for (ll k = 0; k < M; k++) {
                if (ok[A[j][k]]) {
                    selected_num[A[j][k]]++;
                    break;
                }
            }
        }

        ll max_num = 0, max_index = -1;
        for (ll j = 0; j < M; j++) {
            if (selected_num[j] > 0) {
                if (selected_num[j] > max_num) {
                    max_num = selected_num[j];
                    max_index = j;
                }
            }
        }

        ans = min(ans, max_num);

        ok[max_index] = false;
    }

    cout << ans << endl;
}