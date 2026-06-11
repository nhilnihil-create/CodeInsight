#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)
const int MOD = 1000000007;

long long solve(vector<long long> &V, int n) {
    long long res = 0;
    rep(i, 0, n) {
        res += V[i] * (i - n + i + 1);
        res %= MOD;
    }
    return res;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> X(N);
    rep(i, 0, N) cin >> X[i];
    vector<long long> Y(M);
    rep(i, 0, M) cin >> Y[i];
    long long ans = solve(X, N) * (solve(Y, M)) % MOD;
    cout << ans << endl;
    return 0;
}
