#include<bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int dp[100005];
vector<int> g[100005];

void dfs(int x){
    for(int i=0;i<g[x].size();i++){
        dfs(g[x][i]);
    }
    sort(g[x].begin(),g[x].end(),[](int u,int v){
        return dp[u]>dp[v];
    });
    for(int i=0;i<g[x].size();i++){
        dp[x]=max(dp[x],dp[g[x][i]]+i+1);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=2;i<=n;i++){
        cin>>a[i];
        g[a[i]].push_back(i);
    }
    dfs(1);
    cout<<dp[1]<<endl;

    return 0;
}