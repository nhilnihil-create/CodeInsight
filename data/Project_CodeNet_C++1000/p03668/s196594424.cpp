#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
using namespace std;
/// khodaya komak kon
/// ya navid navid
const int N=2e5+100;
vector <int> g[N];
ll ans[N];
ll dfs(ll v,ll p){
    ll cnt=0;
    for (int i=0;i<g[v].size();i++){
        ll u=g[v][i];
        if (u==p){
            continue;
        }
        dfs(u,v);
        cnt^=ans[u]+1;
    }
    ans[v]=cnt;
}
int32_t main(){
    ll n;
    cin >> n;
    for (int i=0;i<n-1;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,1);
    if (ans[1]){
        cout << "Alice" << endl;
    }
    else{
        cout << "Bob" << endl;
    }
}
