#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
vector<ll> adj[N];
ll dfs(ll node){
    vector<ll> a;
    for(auto &v:adj[node])a.push_back(dfs(v));
    sort(a.begin(),a.end());
    ll ans = 0;
    for(auto &ele:a)ans=max(ans,ele)+1;
    return ans;
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n;cin>>n;
    for(ll i=2,x;i<=n;i++)cin>>x,adj[x].push_back(i);
    cout<<dfs(1);
}