#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
   ll n;cin >>n;
   vector<vector<ll>>g(n);
    for (int i = 0; i < n - 1; ++i) {
        ll a,b;cin >>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<ll>que;
    que.push(0);
    vector<ll>d0(n,INF);
    vector<ll>pre(n,INF);
    d0[0]=0;
    while(!que.empty()) {
        ll f = que.front();
        que.pop();
        if(f!=0) {
            d0[f] =d0[pre[f]]+1;
        }
        for (auto u:g[f]) {
            if (d0[u] == INF) {
                que.push(u);
                pre[u]=f;
            }
        }
    }
    vector<ll>dn(n,INF);
    dn[n-1]=0;
    que.push(n-1);
    pre.assign(n,INF);
    while(!que.empty()) {
        ll f = que.front();
        que.pop();
        if(f!=n-1) {
            dn[f] =dn[pre[f]]+1;
        }
        for (auto u:g[f]) {
            if (dn[u] == INF) {
                que.push(u);
                pre[u]=f;
            }
        }
    }
    ll sunu=0;
    ll fen=0;
    for (int i = 0; i < n; ++i) {
//        cout <<d0[i]<<" "<<dn[i]<<endl;
        if(d0[i]<=dn[i]){
            fen++;
        }
        if(d0[i]>dn[i]){
            sunu++;
        }
    }
    if(sunu>=fen){
        puts("Snuke");
    }
    else {
        puts("Fennec");
    }
   return 0;
}

