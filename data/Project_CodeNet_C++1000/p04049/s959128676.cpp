#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
const int N=2e5+100;
vector <int> g[N];
ll dis[N];
queue <int> q;
ll bfs(){
    while(q.size()){
        ll v=q.front();
        q.pop();
        for (int i=0;i<g[v].size();i++){
            ll u=g[v][i];
            if (dis[u]>dis[v]+1){
                dis[u]=dis[v]+1;
                q.push(u);
            }
        }
    }
}
int32_t main(){
    ll n,k;
    cin >> n >> k;
    for (int i=0;i<n-1;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    ll ans=0;
    for (int i=1;i<=n;i++){
        memset(dis,69,sizeof dis);
        dis[i]=0;
        q.push(i);
        bfs();
        ll ma=0;
        for (int j=1;j<=n;j++){
            if (dis[j]<=k/2){
                ma++;
            }
        }
        ans=max(ans,ma);
    }
    for (int i=1;i<=n;i++){
        for (int l=0;l<g[i].size();l++){
            ll v=g[i][l];
            memset(dis,69,sizeof dis);
            dis[i]=0;
            dis[v]=0;
            q.push(i);
            q.push(v);
            bfs();
            ll ma=0;
            for (int j=1;j<=n;j++){
                if (dis[j]<=(k-1)/2){
                    ma++;
                }
            }
            ans=max(ans,ma);
        }
    }
    cout << n-ans;

}
