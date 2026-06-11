#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

struct str{
    ll to,cost;
};
vector<vector<str>>g;
vector<ll>d;
void dfs(ll v,ll now,ll p=-1){
    d[v]=now;
    for(auto u:g[v]){
        if(p==u.to)continue;
        dfs(u.to,now+u.cost,v);
    }
}

int main(){
   ll n;cin >>n;
   g.resize(n);
   d.resize(n);
    for (int i = 0; i < n-1; ++i) {
        ll a,b,c;cin >>a>>b>>c;
        a--;b--;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    ll q,k;cin >>q>>k;
    k--;
    dfs(k,0);
//    for (int j = 0; j < n; ++j) {
//        cout <<j<<" "<<d[j]<<endl;
//    }
    for (int i = 0; i < q; ++i) {
        ll x,y;cin >>x>>y;
        x--;y--;
        cout <<d[x]+d[y]<<endl;
    }
    return 0;
}