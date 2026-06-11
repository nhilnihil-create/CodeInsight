#include<bits/stdc++.h>
using namespace std;
#define nn 100008
#define ll long long
ll n,m,pos[nn],dif[nn];
ll ck;
ll ct[nn];
ll res[nn],cx[nn];
ll c[nn],d[nn];
void mul(ll a[],ll b[])
{
	for(int i=1;i<n;i++) c[i]=i;
	for(int i=1;i<n;i++) c[i]=a[i];
	for(int i=1;i<n;i++) d[i]=c[b[i]];
	for(int i=1;i<n;i++) a[i]=d[i];
}
void qpow()
{
	while(ck)
	{
		if(ck&1) mul(res,cx);
		mul(cx,cx);ck=ck/2;
	}
}
int main()
{
	scanf("%lld",&n);for(int i=1;i<=n;i++) scanf("%lld",&pos[i]);
	for(int i=2;i<=n;i++) dif[i-1]=pos[i]-pos[i-1],cx[i-1]=res[i-1]=i-1;
	scanf("%lld%lld",&m,&ck);
	while(m--)
	{
		ll x;scanf("%lld",&x);
		swap(cx[x-1],cx[x]);
	}
	
	qpow();
	
	ll ct=pos[1];
	for(int i=1;i<=n;i++) printf("%lld\n",ct),ct+=dif[res[i]];
	return 0; 
}