#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;


int N, Ma, Mb;
int dp[50][410][410] = {};

int main() {
    cin >> N >> Ma >> Mb;

    int A[50] = {}, B[50] = {}, C[50] = {};
    for (int i=1; i<=N; i++) cin >> A[i] >> B[i] >> C[i];

    const int INF = 100000000;
    rep(i, 50) rep(a, 410) rep(b, 410) dp[i][a][b] = INF;

    dp[0][0][0] = 0;
    for (int i=1; i<=N; i++) {
        for (int ma=0; ma<=400; ma++) {
            for (int mb=0; mb<=400; mb++) {
                dp[i][ma][mb] = dp[i-1][ma][mb];
                if ((ma>=A[i]) && (mb>=B[i])) {
                    dp[i][ma][mb] = min(dp[i][ma][mb], dp[i-1][ma-A[i]][mb-B[i]] + C[i]);
                }
            }
        }
    }

    int ans = INF, k=1;
    while ((Ma*k <=400) && (Mb*k <=400)) {
        ans = min(ans, dp[N][Ma*k][Mb*k]);
        k++;
    }

    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}

 