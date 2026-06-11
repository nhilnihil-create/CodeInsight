#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
#define int long long
signed main(void){
    int n,W; cin>>n>>W;
    vector <int> w(n),v(n);
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    vector<vector<vector<int>>> dp (n+1, vector<vector<int>>(110 , vector<int>(400))); //見た数、入れた数、重さの端数(?)
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            for(int k=0;k<350;k++){
                
                if((j+1)*w[0]+ k+(w[i]-w[0]) <= W&&k+(w[i]-w[0])<400 )
                chmax(dp[i+1][j+1][k+(w[i]-w[0])] ,dp[i][j][k] + v[i]);
                chmax(dp[i+1][j][k], dp[i][j][k]);
            }
            
        }
    }
    int ans = -114514;
    for(int i=0;i<110;i++){
        for(int j=0;j<400;j++){
            if(i*w[0]+j<=W)
            chmax(ans,dp[n][i][j]);
        }
    }
    cout<<ans<<endl;
}
