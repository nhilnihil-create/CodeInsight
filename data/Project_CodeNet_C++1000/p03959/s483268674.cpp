#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

void solve() {
    int N;
    cin >> N;
    vector<int> T(N), A(N);
    rep(i, N) cin >> T[i];
    rep(i, N) cin >> A[i];
    int T_max = 0, T_max_i = 0;
    rep(i, N) if (T[i] > T_max) {
        T_max = T[i];
        T_max_i = i;
    }
    int A_max = 0, A_max_i = 0;
    rep(i, N) if (A[i] >= A_max) {
        A_max = A[i];
        A_max_i = i;
    }
    if (T_max != A_max || T_max_i > A_max_i) {
        cout << 0 << endl;
        return;
    }
    ll ans = 1, h = 0;
    rep(i, T_max_i + 1) {
        if (T[i] > h) {
            h = T[i];
        } else {
            ans = ans * h % mod;
        }
    }
    rep(i, A_max_i - T_max_i - 1) ans = ans * h % mod;
    for (int i = A_max_i + 1; i < N; i++) {
        if (A[i] < h) {
            h = A[i];
        } else {
            ans = ans * h % mod;
        }
    }
    cout << ans << endl;
    return;
}

int main() {
    solve();
}