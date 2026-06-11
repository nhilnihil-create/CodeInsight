// exp worth blood
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define fs first
#define sc second
#define mp make_pair
using namespace std;
const ll base = 7;
const ll maxn = 2e5 + 9;
const ll inf = 1e6;
typedef pair<ll,ll> LL;
vector<ll> g1[maxn],g2[maxn];
ll cnt1,cnt2;
ll n,k,l,i,j;
ll x,y,res[maxn],col1[maxn],col2[maxn];
bool vis1[maxn],vis2[maxn];
map<ll,ll> mkp;
void dfs1(ll now){
    col1[now] = cnt1;
    vis1[now] = true;
    for (auto i : g1[now]) if (!vis1[i]) dfs1(i);
}
void dfs2(ll now){
    col2[now] = cnt2;
    vis2[now] = true;
    for (auto i : g2[now]) if (!vis2[i]) dfs2(i);
}

int main(){
    ios_base::sync_with_stdio(false);
   	cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin>>n>>k>>l;
    while(k--){
       cin>>x>>y;
       g1[x].pb(y);
       g1[y].pb(x);
    }
    while(l--){
       cin>>x>>y;
       g2[x].pb(y);
       g2[y].pb(x);
    }

    for (i=1;i<=n;i++){
        if (!vis1[i]){
            dfs1(i);
            cnt1++;
        }
        if (!vis2[i]){
            dfs2(i);
            cnt2++;
        }
    }
    for (i=1;i<=n;i++) mkp[col1[i]*inf + col2[i]]++;
    for (i=1;i<=n;i++) cout<<mkp[col1[i]*inf + col2[i]]<<" ";
}
