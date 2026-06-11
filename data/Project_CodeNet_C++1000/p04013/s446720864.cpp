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
    ll n, a; cin >> n >> a;
    vi x(n+1), y(n+1);

    // 入力処理をしつつ最大値を取得（dp配列用）
    ll maxA = a;
    // 1-based
    repf(i, n){
        cin >> x[i];
        y[i] = x[i]-a;
        chmax(maxA, y[i]);
    }

    // y1...ynから任意の枚数選んで合計が0になる組み合わせを数える
    // dp[i][j]; y1..yiから0枚以上選んだ合計がj-n*maxAとなるような選び方
    ll sizeSum = 2*n*maxA+1;
    vvi dp(n+1, vi(sizeSum));

    // yiは負値を取る可能性があるため、0をn*maxA（Aも含めて全て最大値だった場合）にずらす
    // 1枚も選ばないで0となるパターンが1種類
    dp[0][n*maxA] = 1;

    for(ll i=1; i<=n; i++){
        for(ll j=0; j<=sizeSum; j++){
            if(j-y[i]<0 || j-y[i]>2*n*maxA) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] + dp[i-1][j-y[i]];
        }
    }

    // 1枚も選ばないパターンを減算して出力
    cout << dp[n][n*maxA]-1 << endl;
}