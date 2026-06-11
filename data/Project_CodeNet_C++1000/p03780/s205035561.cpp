#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    REP(i, N) cin >> a[i];
    vector<vector<int>> dp_left(N+1, vector<int>(K));
    vector<vector<int>> dp_right(N+1, vector<int>(K));
    dp_left[0][0] = dp_right[N][0] = 1;
    REP(i, N) {
        REP(j, K) {
            dp_left[i+1][j] = dp_left[i][j];
            if (j >= a[i]) dp_left[i+1][j] |= dp_left[i][j-a[i]];
            dp_right[N-i-1][j] = dp_right[N-i][j];
            if (j >= a[N-i-1]) dp_right[N-i-1][j] |= dp_right[N-i][j-a[N-i-1]];
        }
    }
    int ans = 0;
    REP(i, N) {
        vector<int> cum(K+1);
        REP(j, K) cum[j+1] = cum[j] + dp_right[i+1][j];
        bool ok = true;
        REP(j, K) {
            if (!dp_left[i][j]) continue;
            if (cum[K-j] - cum[max(0, K-a[i]-j)] > 0) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }
    cout << ans << endl;
}