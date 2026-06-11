#include <bits/stdc++.h>
using namespace std;
using Int = long long;
constexpr Int MOD = 1e9 + 7;
int main()
{
    int N; cin >> N;
    vector<int> A(N), B(N), mi(N, 1), ma(N, 2e9);
    for (auto &a : A) cin >> a;
    for (auto &b : B) cin >> b;
    for (int i = 0; i < N; i++) {
        int prev = (i == 0 ? 0 : A[i-1]);
        if (prev < A[i]) mi[i] = max(mi[i], A[i]);
        ma[i] = min(ma[i], A[i]);
    }
    for (int i = N-1; i >= 0; i--) {
        int prev = (i == N-1 ? 0 : B[i+1]);
        if (prev < B[i]) mi[i] = max(mi[i], B[i]);
        ma[i] = min(ma[i], B[i]);
    }
    Int ans = 1;
    for (int i = 0; i < N; i++) {
        if (mi[i] > ma[i]) ans = 0;
        else ans = ans * (ma[i] - mi[i] + 1) % MOD;
    }
    cout << ans << endl;
    return 0;
}