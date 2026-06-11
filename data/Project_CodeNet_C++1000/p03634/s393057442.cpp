#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

vector<int>to[100010],co[100010];
vector<ll>ans;

void dfs(int v, ll x, int p=-1){
    ans[v]=x;
    rep(i,to[v].size()){
        if(to[v][i]==p)continue;
        dfs(to[v][i],x+co[v][i],v);
    }
}

int main(){
    int n;
    cin>>n;
    ans.resize(n);
    rep(i,n-1){
        int a,b,c;
        cin>>a>>b>>c;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
        co[a].push_back(c);
        co[b].push_back(c);
    }
    int q,k;
    cin>>q>>k;
    k--;
    dfs(k,0);
    vector<int>d(q),f(q);
    rep(i,q){
        cin>>d[i]>>f[i];
        d[i]--; f[i]--;
    }
    rep(i,q)cout<<ans[d[i]]+ans[f[i]]<<endl;
    return 0;
}