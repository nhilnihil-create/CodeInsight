#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

#define INF (1ll<<60)


long long M = 1000000007;
long long n,k,tmpl;
vector<vector<int>> G;
vector<long long> l;

bool dfs(int u){
    if(l[u]<=k/2)tmpl++;
    for(int v:G[u]){
        if(l[v]==-1){
            l[v]=l[u]+1;
            dfs(v);
        }
    }
    return 0;
}

int main(int argc, char const *argv[]) {
    cin>>n>>k;
    G = vector<vector<int>>(n,vector<int>(0));
    vector<int> us(n-1),vs(n-1);
    for(int i=0;i<n-1;++i){
        int u,v;cin>>u>>v;
        u--;v--;
        G[u].push_back(v);
        G[v].push_back(u);
        us[i]=u;
        vs[i]=v;
    }
    long long res = n;
    if(k%2==0){
        for(int i=0;i<n;++i){
            tmpl = 0;
            l = vector<long long>(n,-1);
            l[i] = 0;
            dfs(i);
            res = min(res,n-tmpl);
        }
    }
    else{
        for(int i=0;i<n-1;++i){
            tmpl = 0;
            l = vector<long long>(n,-1);
            l[us[i]] = 0;
            l[vs[i]] = 0;
            dfs(us[i]);
            dfs(vs[i]);
            res = min(res,n-tmpl);
        }
    }
    cout<<res<<endl;
    return 0;
}