#include<bits/stdc++.h>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long int ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
const ll INF=1000000010;
const ll LINF=4000000000000000010LL;
const int MAX=310;
const double EPS=1e-3;
int dx[4]={0,1,0,1};
int dy[4]={0,0,1,1};
vector<int> G[100010];
ll a[100010];
bool ans;
void dfs(int v,int p){
	ll sum=0;
	ll ma=0;
	if(G[v].size()==1)return;
	for(auto e:G[v]){
		if(e==p)continue;
		dfs(e,v);
		sum+=a[e];
		ma=max(ma,a[e]);
	}
	if(a[v]>sum){
		ans=false;
	}else if(a[v]<sum){
		if(ma>a[v]){
			ans=false;
		}
		if((sum-a[v])*2LL>sum){
			ans=false;
		}else{
			a[v]=sum-(sum-a[v])*2LL;
		}
	}
}
int main(){
	ans=true;
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==2){
		if(a[0]!=a[1]){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
		return 0;
	}
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int v;
	for(int i=0;i<n;i++){
		if(G[i].size()!=1){
			v=i;
			break;
		}
	}
	dfs(v,-1);
	if(a[v])ans=false;
	if(ans){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
    return 0;
}
