#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=3e5+7;
const ll INF=1e9+7;
ll n,l,t;
ll x[N],w[N],u[N],a[N];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	scanf("%lld%lld%lld",&n,&l,&t);
	rep(i,n)scanf("%lld%lld",&x[i],&w[i]);
	rep(i,n){
		if(w[i]&1)u[i]=(x[i]+t)%l;
		else u[i]=(x[i]-t%l+l)%l;
	}
	ll nw=u[1],id=0,gg;
	sort(u+1,u+n+1);
	rep(i,n){
		if(w[i]==w[1])continue;
		ll g=(w[1]&1)?(x[i]-x[1]):(x[1]-x[i]+l),q=(2*t)%l;
		(id+=(2*t)/l)%=n;
		if(g<=q)id=(id+1)%n;
	}
	if(w[1]==2)id=n-id;
	id=id%n+1;
	if(w[1]&1){for(ll i=n;i;i--)if(u[i]==nw){gg=i; break;}}
	else {rep(i,n)if(u[i]==nw){gg=i; break;}}
	rep0(i,n)a[(id-1+i)%n+1]=u[(gg+i-1)%n+1];
	rep(i,n)printf("%lld\n",a[i]);
	return 0;
}
