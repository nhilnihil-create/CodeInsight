#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a,b,v[55],c[55][55],ans2;
double sum,ans;
int main(){
	scanf("%lld%lld%lld",&n,&a,&b);
	for(ll i=1;i<=n;i++) c[i][0]=c[i][i]=1;
	for(ll i=2;i<=n;i++) for(ll j=1;j<i;j++) c[i][j]=c[i-1][j-1]+c[i-1][j];
	for(ll i=0;i<n;i++) scanf("%lld",&v[i]);
	sort(v,v+n,greater<ll>());
	for(ll i=0;i<a;i++) sum+=v[i];
	ans=sum/a;
	printf("%lf\n",ans);
	int all=0,x=0,y=0;
	for(ll i=0;i<n;i++) if(v[i]==v[a-1]) all++;
	for(ll i=0;i<a;i++) if(v[i]==v[a-1]) x++;
	for(ll i=0;i<b;i++) if(v[i]==v[a-1]) y++;
	if(v[a-1]!=v[0]) ans2=c[all][x];
	else for(ll i=x;i<=y;i++) ans2+=c[all][i];
	printf("%lld\n",ans2);
	return 0;
}