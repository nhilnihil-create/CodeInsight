#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
ll dp[55][55][2505] = {0};
int main() {
    ll N, A; cin >> N >> A;
    vector<ll> x(N+1);
    rep(i, N) cin >> x[i+1];
    dp[0][0][0] = 1;
    for(ll j=1;j<=N;j++) {
        for(ll k=0;k<=N;k++) {
            for(ll s=0;s<=N*50;s++) {
                if(s < x[j])
                dp[j][k][s] = dp[j-1][k][s];
                else if(k>=1 && s >= x[j])
                dp[j][k][s] = dp[j-1][k][s] + dp[j-1][k-1][s-x[j]];
                else
                dp[j][k][s] = 0;
            }
        }
    }
    ll ans = 0;
    for(int k=1;k<=N;k++) ans+=dp[N][k][k*A];
    cout << ans;
}
