#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll n, w, ans = 0; cin >> n >> w;
    vi weight(n), value(n);
    cin >> weight[0] >> value[0];
    ll ofs = weight[0];

    // weight[0]を1として正規化
    repf(i, n-1){
        cin >> weight[i] >> value[i];
        weight[i] -= weight[0];
    }
    weight[0] = 0;

    // dp[i][j][k]; i番目の商品まででj個使って重さkの場合の最大価値
    vector<vvi> dp(n+1, vvi(n+1, vi((n+1)*3+1)));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            for(ll k=0; k<=n*3+1; k++){
                //chmax(dp[i+1][j][k], dp[i][j][k]);
                if(weight[i] <= k) dp[i+1][j+1][k] = max(dp[i][j+1][k], dp[i][j][k-weight[i]] + value[i]);
                else dp[i+1][j+1][k] = dp[i][j+1][k];
            }
        }
    }

    // テーブルを参照して最大値を出力
    for(ll j=1; j<=n; j++){
        if(w-j*ofs<0) continue;
        chmax(ans, dp[n][j][min(3*n, w-j*ofs)]);
    }
    cout << ans << endl;
}