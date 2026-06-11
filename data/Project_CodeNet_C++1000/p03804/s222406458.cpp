#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;
// ------------------------------

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    vector<string> B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];
    rep(i, N - M + 1) rep(j, N - M + 1) {
        bool flag = true;
        rep(k, M) rep(l, M) {
            if (A[i + k][j + l] != B[k][l]) flag = false;
        }
        if (flag) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}