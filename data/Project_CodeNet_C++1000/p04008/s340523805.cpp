#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define all(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define mad(a,b) a=(a+b)%mod
#define N 100010
vector<ll> g[N];
ll dep[N];
void dfs1(ll x,ll d){
	dep[x]=d;
	for(auto y:g[x]){
		dfs1(y,d+1);
	}
}
bool used[N];
void dfs2(ll x){
	if(used[x])return;
	used[x]=1;
	for(auto y:g[x]){
		dfs2(y);
	}
}
ll n,k,p[N];
int main(){
	cin>>n>>k;
	k=min(k,n);
	rep(i,n){
		cin>>p[i]; p[i]--;
		if(i!=0)g[p[i]].push_back(i);
	}
	ll ans=(p[0]!=0);
	p[0]=0;
	dfs1(0,0);
	vector<P> v;
	rep(i,n){
		v.push_back(make_pair(dep[i],i));
	}
	sort(all(v),greater<P>());
	rep(i,n)used[i]=0;
	for(auto e:v){
		ll x=e.second;
		if(used[x])continue;
		rep(i,k-1)x=p[x];
		ans+=(p[x]!=0);
		dfs2(x);
	}
	cout<<ans<<endl;
}



