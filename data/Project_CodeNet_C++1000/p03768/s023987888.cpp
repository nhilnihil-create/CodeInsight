#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pcc pair<char,char>
#define vi vector <int>
#define vl vector <ll>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d",x)
#define plld(x) printf("%lld",x)
#define pds(x) printf("%d ",x)
#define pllds(x) printf("%lld ",x)
#define pdn(x) printf("%d\n",x)
#define plldn(x) printf("%lld\n",x)
#define INF 2e9
#define INFLL 4e18
using namespace std;
ll powmod(ll base,ll exponent,ll mod){ // with mod < 1e9
	ll ans=1;
	while(exponent){
		if(exponent&1)ans=(ans*base)%mod;
		base=(base*base)%mod;
		exponent/=2;
	}
	return ans;
}
ll gcd(ll a, ll b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
const int upperlimit = 1e6+1;
const int mod = 1e9+7;
struct data{
	int nd,d,col;
};
vi adj[upperlimit];
int colour[upperlimit];
int mxdst[upperlimit];
data queries[upperlimit];
queue <data> vert;
void bfs(){
	while(! vert.empty()){
		data x=vert.front();
		int node=x.nd;
		int k=x.d;
		if(k<=mxdst[node]){
			vert.pop();
			continue;
		}
		mxdst[node]=k;
		if(! colour[node]) colour[node]=x.col;
		if(! k){
			vert.pop();
			continue;
		}
		for(int i = 0; i < adj[node].size(); i++){
			data temp;
			temp.nd=adj[node][i];temp.d=k-1;temp.col=x.col;
			vert.push(temp);
		}
		vert.pop();
	}
}
int main() {
	int n,m,a,b,q;
	sd(n);sd(m);
	for(int i = 1; i <= m; i++){
		sd(a);sd(b);
		adj[a].pb(b);adj[b].pb(a);
	}
	for(int i = 1; i <= n; i++) mxdst[i]=-1;
	sd(q);
	for(int i = q; i >= 1; i--){
		sd(queries[i].nd);sd(queries[i].d);sd(queries[i].col);
	}
	for(int i = 1; i <= q; i++){
		vert.push(queries[i]);
		bfs();
	}
	for(int i = 1; i <= n; i++) pdn(colour[i]);
	return 0;
}