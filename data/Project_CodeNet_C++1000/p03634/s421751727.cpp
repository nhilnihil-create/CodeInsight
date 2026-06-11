#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
vector<P> to[100001];
ll d[100001]={};
ll n,q,k;
void dfs(int i,int par){
    for(auto x:to[i]){
        if(x.first!=par){
            d[x.first]=d[i]+x.second;
            dfs(x.first,i);
        }
    }
}
int main(void){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        to[a].push_back(P(b,c));
        to[b].push_back(P(a,c));
    }
    cin>>q>>k;
    dfs(k,-1);
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        cout<<d[x]+d[y]<<endl;
    }
}