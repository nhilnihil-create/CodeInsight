#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2
 
using namespace std;
int MOD = 1000000007;

#define N 310
int dp[N][N];
int ukai[N][N];
int a[N][N] = {0};
    
signed main(){
    
    int n;
    cin >> n;
    rep(i,n) rep(j,n) dp[i][j] = INF;
    rep(i,n) rep(j,n) ukai[i][j] = INF;

    rep(i,n){
        rep(j,n){
            cin >> dp[i][j]; 
            a[i][j] = dp[i][j];
        }
    }

    rep(k,n){
        rep(i,n){
            rep(j,n){
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
            }
        }
    }

    rep(i,n){
        rep(j,n){
            rep(k,n){
                if(i == k || j == k)continue;
                ukai[i][j] = min(ukai[i][j],dp[i][k] + dp[k][j]);
            }
        }
    }
    rep(i,n){
        rep(j,n){
            cerr << dp[i][j] << " "; 
        }
        cerr << endl;
    }
    cerr << endl;
    rep(i,n){
        rep(j,n){
            cerr << ukai[i][j] << " "; 
        }
        cerr << endl;
    }

    int ans = 0;
    rep(i,n){
        for(int j = i+1;j<n;j++){
            if(dp[i][j] != a[i][j]){
                cout << -1 << endl;
                return 0;
            }
            if(ukai[i][j] > dp[i][j]){
                ans += dp[i][j];
            }
        }
    }
    cout << ans << endl;

    

    return 0;   
}
// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://ddcc2019-final.contest.atcoder.jp/tasks/ddcc2019_final_a
// rm -r -f test;oj dl http://abc118.contest.atcoder.jp/tasks/abc118_a