#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    int N, M; cin >> N >> M;
    vector<int> x(M), y(M); rep(i, M) cin >> x[i] >> y[i];

    vector<int> B(N + 1, 1);
    vector<bool> R(N + 1, false);
    R[1] = true;
    int a, b;
    rep(i, M) {
        a = x[i]; b = y[i];
        B[a]--; B[b]++;
        if (R[a]) {
            R[b] = true;
            if (B[a] == 0) R[a] = false;
        }
    }
    int ans = 0;
    rep(i, N + 1) if (R[i]) ans++;
    cout << ans << '\n';

    return 0;
}