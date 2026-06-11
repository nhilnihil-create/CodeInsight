#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
const int MAX = 1e5;

vector<int> g[MAX];
vector<int> dp(MAX,-1);

int dfs(int i, int p){
    if(dp[i] != -1) return dp[i];
    vector<int> v;
    rep(j,g[i].size()){
        if(g[i][j] != p) v.push_back(dfs(g[i][j],i));
    }
    sort(v.begin(),v.end(),greater<int>());
    rep(i,v.size()) v[i] += i+1;
    int d = 0;
    rep(i,v.size()) d = max(d,v[i]);
    return dp[i] = d;
}

int main(){
    int n;
    cin >> n;
    rep(i,n-1) {
        int a;
        cin >> a;
        a--;
        g[a].push_back(i+1);
        g[i+1].push_back(a);
    }
    cout << dfs(0,-1) << endl;
    return 0;
}