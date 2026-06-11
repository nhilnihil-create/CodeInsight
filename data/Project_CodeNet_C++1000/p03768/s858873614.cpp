#include <bits/stdc++.h>
using namespace std;
#define int long long



signed main(){
    int n,m,a,b;
    cin >>n>>m;
    vector<int> hen[n];
    for(int i=0;i<m;i++){
        cin >>a>>b;
        hen[a-1].push_back(b-1);
        hen[b-1].push_back(a-1);

    }
    pair<int,int> dp[11][n],ans[n];
    for(int i=0;i<11;i++)for(int j=0;j<n;j++)dp[i][j]=make_pair(0,0);
    for(int i=0;i<n;i++)ans[i]=make_pair(0,0);
    int q,v,d,c;
    cin >>q;
    for(int i=0;i<q;i++){
        cin >>v>>d>>c;
        dp[d][v-1]=make_pair(i+1,c);
    }
    for(int i=10;i>0;i--){
        for(int j=0;j<n;j++){
            if(ans[j].first<dp[i][j].first)ans[j]=dp[i][j];
            for(int k=0;k<hen[j].size();k++){
                if(dp[i-1][hen[j][k]].first<dp[i][j].first)dp[i-1][hen[j][k]]=dp[i][j];
            }
        }
    }
    for(int j=0;j<n;j++){
            if(ans[j].first<dp[0][j].first)cout <<dp[0][j].second<<endl;
            else cout << ans[j].second<<endl;
    }

       

    return 0;
}