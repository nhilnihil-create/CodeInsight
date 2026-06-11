#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define RREP(i,n) for (int i=(n)-1;i>=0;--i)
#define all(a) (a).begin(),(a).end()

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, L, Q;
    cin >> N;
    vector<int> x(N);
    REP(i, N) cin >> x[i];
    cin >> L >> Q;

    int K = 31 - __builtin_clz(N - 1); // floor(log(max(b - a)))
    vector<vector<int>> dp(N, vector<int>(K + 1));
    REP(i, N) {
        dp[i][0] = distance(x.begin(), upper_bound(all(x), x[i] + L)) - 1;
        //printf("dp[%d][0] = %d\n", i, dp[i][0]);
    }
    FOR(j, 1, K + 1) REP(i, N) {
        dp[i][j] = dp[dp[i][j - 1]][j - 1];
    }

    REP(_, Q) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        if (a > b) {
            swap(a, b);
        }
        int result = 0;
        RREP(i, K + 1) {
            if (dp[a][i] < b) {
                //printf("from x[%d] to x[%d] in %d days\n", a, dp[a][i], 1 << i);
                a = dp[a][i];
                result += 1 << i;
            }
        }
        ++result;
        cout << result << '\n';
    }
    cout << flush;

    return 0;
}