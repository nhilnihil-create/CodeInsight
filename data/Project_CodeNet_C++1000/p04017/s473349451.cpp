#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<ll> X(N);
    REP(i, 0, N) cin >> X[i];

    int L; cin >> L;
    int k = 1; while ((1 << k) < N) k++;
    int next[k][N] = {};
    REP(i, 0, N) {
        int idx = upper_bound(ALL(X), X[i] + L) - X.begin() - 1;
        next[0][i] = idx;
        // cout << X[idx] << endl;
    }
    REP(i, 0, k - 1) {
        REP(j, 0, N) {
            if (next[i][j] < 0) {
                next[i + 1][j] = -1;
            } else {
                next[i + 1][j] = next[i][next[i][j]];
            }
        }
    }

    int Q; cin >> Q;
    while (Q--) {
        int a, b; cin >> a >> b; a--; b--;
        if (a > b) swap(a, b);
        
        int ans = 0;
        for (int i = k - 1; i >= 0; i--) {
            if (next[i][a] < b) {
                ans += (1 << i);
                a = next[i][a];
            }
        }
        cout << ans + 1 << endl;
    }
    return 0;
}