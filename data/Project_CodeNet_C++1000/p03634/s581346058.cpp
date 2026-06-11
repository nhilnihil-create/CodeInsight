#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
vector<P> to[100001];
ll d[100001]={};
void dfs(ll i,ll par){
    for(auto x:to[i]){
        if(x.first!=par){
            d[x.first]=d[i]+x.second;
            dfs(x.first,i);
        }
    }
}

int main(void){
    ll n,q,k;
    cin>>n;
    for(int i=0;i<n-1;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        to[a].push_back(make_pair(b,c));
        to[b].push_back(make_pair(a,c));
    }
    cin>>q>>k;
    dfs(k,-1);
    for(int i=0;i<q;i++){
        ll x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",d[x]+d[y]);
    }
}