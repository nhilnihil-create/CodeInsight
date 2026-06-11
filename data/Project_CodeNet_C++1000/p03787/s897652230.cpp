#include <bits/stdc++.h>
typedef long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
vector <int> g[N];
ll vis[N],r[N];
ll p1=0;
void dfs(ll v,ll k){
    vis[v]=1;
    r[v]=k;
    for (auto u : g[v]){
        if (!vis[u]){
            dfs(u,3-k);
        }
        else{
            if (r[u]==r[v]) p1=1;
        }
    }
    return;
}
int32_t main(){
    ll n,m;
    cin >> n >> m;
    for (int i=1;i<=m;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    ll cnt=0;
    for (int i=1;i<=n;i++){
        if (g[i].size()==0){
            cnt++;
        }
    }
    ll ans=cnt*(n-cnt)*2+cnt*cnt;
    ll t0=0,t1=0;
    for (int i=1;i<=n;i++){
            p1=0;
        if (g[i].size()==0 || vis[i]) continue;
        dfs(i,1);
     //   cout << i << " " << p1 << endl;
        if (p1) t1++;
        else t0++;
    }
   // cout << ans << " " << t0 << " " << t1 << endl;
    ans+=2*t0+t1+t0*(t0-1)*2+(t1-1)*t1;
    ans+=t0*t1*2;
    cout << ans << endl;

}
