#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define endl "\n"
#define pll pair<ll,ll>
#define all(x) (x).begin() , (x).end()
#define f first
#define s second
#define pr(x) cout<<x<<endl;
#define pr2(x,y) cout<<x<<" "<<y<<endl;
#define pr3(x,y,z) cout<<x<<" "<<y<<endl;
#define prv(v) for(auto x:v) cout<<x<<" ";
#define ffs fflush(stdout);
#define int ll
using namespace std;
 
const ll N =(2e5+5);
const ll MOD = 1e9+7;
const ll INF = LLONG_MAX;
const ll LOG = 29;
#define PI 3.141592653589793238 
 
 
long long binpow(long long a, long long b) {
    a%=MOD;    
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%MOD;
        a = (a * a)%MOD;
 
        
        b >>= 1;
    }
    res%=MOD;
    return res;
}
vll adj[N];
bool vis[N];
ll cnt = 0;

void dfs(ll u){
    vis[u]=true;
    for(auto v:adj[u]){
        if(!vis[v])
            dfs(v);
    }
    cnt++;
}

void solve(){

    ll n,m;
    cin>> n >> m;
    ll src = -1;
    for(int i =1;i<=m;i++){
        ll u,v;
        cin>> u >> v;
        if(src==-1)src=  u;
        adj[u].pb(v);
    
        adj[v].pb(u);
    
    }

    for(int i =1;i<=n;i++){
        ll d = adj[i].size()*1ll;
        if(d % 2!=0){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
     
    ll t=1;
    while(t--){
        solve();
    }    
}
