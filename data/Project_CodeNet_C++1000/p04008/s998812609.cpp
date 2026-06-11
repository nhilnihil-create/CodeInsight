#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
vector<ll> adj[N];
ll n,k,ans;
ll dfs(ll src,ll pr){
    ll mx=0;
    for(auto &v:adj[src])mx=max(mx,dfs(v,src));
    if(mx==k-1){
        if(pr!=0)ans++;
        return 0;
    }
    return mx+1;
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(ll i=0;i<n;i++){
        ll p;cin>>p;
        p--;
        if(i==0){
            if(p!=0)ans++;
        }
        else adj[p].push_back(i);
    }
    dfs(0,0);
    cout<<ans;
}