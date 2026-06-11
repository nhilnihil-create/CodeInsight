#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1e8;
vector<vector<int>> dp(401,vector<int> (401,INF));

int main(){
    int n,ma,mb; cin >> n >> ma >> mb;
    vector<vector<int>> vec(n,vector<int> (3));
    rep(i,n) cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
    dp[0][0] = 0;
    rep(i,n){
        int a = vec[i][0], b = vec[i][1], c = vec[i][2];
        for(int x = 400; x >= a;--x){
            for(int y = 400; y >= b;--y){
                dp[x][y] = min(dp[x][y],dp[x-a][y-b]+c);
            }
        }
    }
    int ans = INF;
    for(int i = 1;i <= min(400/ma,400/mb);++i){
        ans = min(ans,dp[i*ma][i*mb]);
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}
