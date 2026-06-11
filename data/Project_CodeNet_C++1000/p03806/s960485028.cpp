#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;
int dp[50][10000];

int main() {
    int N,a,b;
    cin>>N>>a>>b;
    vector<vector<int>> v(N,vector<int>(3));
    for(int i = 0; i < N; i++) cin>>v[i][0]>>v[i][1]>>v[i][2];
    vector<int> d(N);
    for(int i = 0; i < N; i++) d[i]=b*v[i][0]-a*v[i][1];
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 10000; j++) dp[i][j]=INF;
    }
    dp[0][5000]=0;
    dp[0][5000+d[0]]=v[0][2];
    int ans = INF;
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < 10000; j++){
            if(dp[i][j]==-1) continue;
            chmin(dp[i+1][j],dp[i][j]);
            chmin(dp[i+1][j+d[i+1]],dp[i][j]+v[i+1][2]);
            if(j+d[i+1]==5000) chmin(ans,dp[i][j]+v[i+1][2]);
        }
    }
    if(ans==INF) cout<<-1<<endl;
    else cout<<ans<<endl;
}