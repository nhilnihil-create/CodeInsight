#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+10;
ll n,m,k,p;
ll x[N],id[N],sta[N],ans[N],vis[N];
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&x[i]),id[i]=i;
	for(ll i=n;i>=1;i--) x[i]-=x[i-1];
	scanf("%lld%lld",&m,&k);
	for(ll i=1;i<=m;i++) scanf("%lld",&p),swap(id[p],id[p+1]);
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			ll cnt=0;
			for(ll j=i;!vis[j];j=id[j]) sta[++cnt]=j,vis[j]=1;
			for(ll j=1;j<=cnt;j++) ans[sta[j]]=x[sta[(j+k-1)%cnt+1]];
		}
	}
	for(ll i=1;i<=n;i++) ans[i]+=ans[i-1],printf("%lld.0\n",ans[i]);
}