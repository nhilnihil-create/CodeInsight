#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N,M; cin>>N>>M;
    map<int,set<int>> adj;
    rep(m,0,M){
        int a,b; cin>>a>>b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    string ans="IMPOSSIBLE";
    for(auto a:adj[1]){
        if(adj[a].count(N)) ans="POSSIBLE";
    }

    cout<<ans<<endl;
}