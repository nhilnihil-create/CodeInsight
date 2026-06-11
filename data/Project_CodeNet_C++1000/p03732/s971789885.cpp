#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define int long long
signed main(){
//int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,wlim;
    cin >> n >> wlim;
    vector<int> w(n);
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    int dp[n+5][n+5][3*n+15];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            for(int k = 0; k <= 3*n; k++) {
                int rem=w[i]-w[0];
                chmax(dp[i+1][j][k], dp[i][j][k]);
                chmax(dp[i+1][j+1][k+rem], dp[i][j][k] + v[i]);
            }
        }
    }

    int ans=0;
    for(int j = 0; j <= n ; j++) {
        for(int k = 0; k <= 3*n ; k++) {
            if(j*w[0]+k <= wlim) ans=max(ans,dp[n][j][k]);
        }
    }
    cout << ans << "\n";

    return 0;
}