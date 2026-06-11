#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back

int N, K;
long long a[5010];
bool dp1[5010][5010], dp2[5010][5010];
vector<int> acc[5010];

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> K;
    rep(i, N) cin >> a[i];
    
    dp1[0][0] = true;
    rep(i, N) rep(j, K) {
        dp1[i+1][j] |= dp1[i][j];
        if (j+a[i]<K) dp1[i+1][j+a[i]] |= dp1[i][j];
    }
    dp2[0][0] = true;
    rep(i, N) rep(j, K) {
        dp2[i+1][j] |= dp2[i][j];
        if (j+a[N-1-i]<K) dp2[i+1][j+a[N-1-i]] |= dp2[i][j];
    }
    
    rep(i, N) {
        acc[i].pb(0);
        rep(j, K) acc[i].pb(acc[i].back()+dp2[i][j]);
    }
    int ans = 0;
    rep(i, N) {
        bool need = false;
        rep(j, K) {
            if (dp1[i][j]==0) continue;
            int l = max(0ll, K-a[i]-j);
            int h = K-j;
            if (acc[N-i-1][h]-acc[N-i-1][l]>0) need = true;
        }
        if (!need) ans++;
    }
    cout << ans << endl;
}