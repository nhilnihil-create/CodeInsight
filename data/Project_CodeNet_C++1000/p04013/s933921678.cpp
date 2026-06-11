#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
    int N, A;
    cin >> N >> A;
    vector<int> X(N);
    rep(i, N) cin >> X[i];

    sort(X.begin(), X.end());
    rep(i, N) X[i] -= A;

    vector<int> L, R;
    int n_zero = 0;
    for (auto x : X) {
        if (x < 0) {
            L.push_back(x);
        } else if (x > 0) {
            R.push_back(x);
        } else {
            n_zero++;
        }
    }

    const int M = 50 * 50 + 1;
    vector<ll> S_L(M, 0);
    for (auto l : L) {
        l = -l;
        for (int i = M; 1 <= i - l; i--) {
            S_L[i] += S_L[i - l];
        }
        S_L[l]++;
    }

    vector<ll> S_R(M, 0);
    for (auto r : R) {
        for (int i = M; 1 <= i - r; i--) {
            S_R[i] += S_R[i - r];
        }
        S_R[r]++;
    }

    ll n_comb = 0;
    rep(i, M) n_comb += S_L[i] * S_R[i];

    ll ans = (n_comb + 1) * pow(2, n_zero) - 1;
    cout << ans << endl;

    return 0;
}