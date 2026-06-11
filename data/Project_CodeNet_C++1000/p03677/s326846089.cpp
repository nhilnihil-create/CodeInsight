#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=100050;
int n,m;
ll a[maxn],b[maxn<<1],c[maxn<<1];
int main(){
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(register int i=1;i<n;i++){
		if(a[i+1]==a[i])continue;
		if(a[i+1]<a[i])b[a[i+1]+m+1]--,b[a[i]+1]++,c[a[i+1]+m+1]-=a[i+1]+m-a[i];
		else b[a[i]+1]++,b[a[i+1]+1]--,c[a[i+1]+1]-=a[i+1]-a[i];
	}
	ll tot=0;
	for(register int i=1;i<=2*m;i++)b[i]+=b[i-1];
	for(register int i=1;i<=2*m;i++)c[i]+=c[i-1]+b[i];
	for(register int i=1;i<=m;i++)b[i]+=b[i+m],c[i]+=c[i+m],tot+=b[i];
	ll ans=99999999999999LL;
	for(register int i=1;i<=m;i++)ans=min(ans,tot-c[i]+b[i]);
	cout<<ans<<endl;
}