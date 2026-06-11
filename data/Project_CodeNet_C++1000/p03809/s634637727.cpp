#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e5+5;
vector<ll> adj[N];
ll a[N];
ll dfs(ll u,ll pr){
    ll cnt=0,mx=0,sum=0;
    for(auto &v:adj[u]){
        if(v==pr)continue;
        cnt++;
        ll tmp = dfs(v,u);
        sum+=tmp;
        mx=max(mx,tmp);
    }
    if(!cnt)return a[u];

    if(a[u] > sum || a[u]<mx || 2*a[u] < sum){
        cout<<"NO";
        exit(0);
    }
    return 2*a[u]-sum;
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n;cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];

    if(n==2){
        cout<<(a[1]==a[2]?"YES":"NO");
        return 0;
    }

    for(ll i=0,u,v;i<n-1;i++)cin>>u>>v,adj[u].push_back(v),adj[v].push_back(u);

    ll root=1;
    while(adj[root].size()==1)root++;
    ll ans=dfs(root,root);
    cout<<(ans?"NO":"YES");
}
