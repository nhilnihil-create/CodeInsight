#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N, K;
int a[5010];
bool dp[5010][5010];

bool judge(int x) {
    rep(i, N) rep(j, K) dp[i][j] = false;
    dp[0][0] = true;
    rep(i, N-1) {
        int v = a[i+(i>=x ? 1:0)];
        rep(j, K) {
            dp[i+1][j] |= dp[i][j];
            if (j+v<K) dp[i+1][j+v] |= dp[i][j];
        }
    }
    for (int i=max(0ll, K-a[x]); i<K; i++) if (dp[N-1][i]) return false;
    return true;
}

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> K;
    rep(i, N) cin >> a[i];
    sort(a, a+N);
    int l = 0, r = N-1;
    while (l<=r) {
        int m = (l+r)/2;
        if (judge(m)) l = m+1;
        else r = m-1;
    }
    cout << r+1 << endl;
}