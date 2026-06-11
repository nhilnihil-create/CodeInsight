#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#define mod 1000000007
using namespace std;
typedef long long ll;
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)
#define mad(a,b) a=(a+b)%mod
#define mul(a,b) a=a*b%mod

#define N 100010
ll n,a[N];
vector<ll> g[N];
bool dfs(ll x,ll from){
    ll sum=0,ma=-1;
    for(auto y:g[x])if(y!=from){
	if(dfs(y,x)==0)return 0;
	sum+=a[y];
	chmax(ma,a[y]);
    }
    if(ma==-1)return 1;
    ll rem=sum-a[x];
    if(rem<0)return 0;
    if(sum-ma<rem)return 0;
    a[x]-=rem; if(a[x]<0)return 0;
    return 1;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=0;i<n-1;i++){
	ll a,b; cin>>a>>b;
	g[a].push_back(b);
	g[b].push_back(a);
    }
    if(n==2){
	cout<<(a[1]==a[2]?"YES":"NO")<<endl;
	return 0;
    }
    ll p=1;
    for(;g[p].size()==1;p++){}
    if(dfs(p,0)==1&&a[p]==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

