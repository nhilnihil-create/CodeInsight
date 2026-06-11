#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define all(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define mad(a,b) a=(a+b)%mod
#define N 100010
#define D 60
ll n,x[N],m,k;
ll dist[N];

typedef struct jun{
	ll p[N];
}jun;
jun merge(jun a,jun b){
	jun c;
	rep(i,n-1)c.p[i]=b.p[a.p[i]];
	return c;
}
jun po[60];

int main(){
	cin>>n;
	rep(i,n)cin>>x[i];
	ll value[N];
	rep(i,n-1)value[i]=i;
	cin>>m>>k;
	rep(i,m){
		ll a; cin>>a; a--;
		swap(value[a-1],value[a]);
	}
	rep(i,n-1)po[0].p[value[i]]=i;
	for(int d=1;d<60;d++){
		po[d]=merge(po[d-1],po[d-1]);
	}
	jun gen;
	rep(i,n-1)gen.p[i]=i;
	for(int d=0;d<60;d++){
		if(k&1)gen=merge(gen,po[d]);
		k>>=1;
	}
	rep(i,n-1)dist[gen.p[i]]=x[i+1]-x[i];
	for(int i=1;i<n;i++)x[i]=x[i-1]+dist[i-1];
	rep(i,n)cout<<x[i]<<endl;
}



