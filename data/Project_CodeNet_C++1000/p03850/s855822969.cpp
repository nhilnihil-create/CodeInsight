#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+50;
ll n,ans,pos;
ll a[N],t[N],s1[N],s2[N];
char s[10];
int main()
{
	ll i;
	scanf("%lld",&n);
	scanf("%lld",&a[1]);t[1]=1;
	for(i=2;i<=n;i++)
	{
		scanf("%s",s);scanf("%lld",&a[i]);
		if(s[0]=='+') t[i]=1;
		else t[i]=-1;
	}
	for(i=1;i<=n;i++) s1[i]=s1[i-1]+t[i]*a[i],s2[i]=s2[i-1]+a[i];
	ans=s1[n];
	pos=n+1;
	for(i=n;i>=2;i--)
	{
		if(t[i]==-1) 
		{
			ans=max(ans,s1[i-1]-(s2[pos-1]-s2[i-1])+s2[n]-s2[pos-1]);
			pos=i;
		}
	}
	printf("%lld\n",ans);
	return 0;
}