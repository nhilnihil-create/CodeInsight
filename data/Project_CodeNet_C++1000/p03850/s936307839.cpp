#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100005],hz[100005];
char s[100005];
int max(int x,int y)
{
	return x>y?x:y;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<n;++i)
	{
		scanf("%lld",&a[i]);
		scanf(" %c",&s[i]);
	}
	scanf("%lld",&a[n]);
	s[0]='+';
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i-1]=='+')ans+=a[i];
		else ans-=a[i];
	}
	hz[n]=a[n];
	for(int i=n-1;i>=1;--i)hz[i]=hz[i+1]+a[i];
	int now=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i-1]=='+')now+=a[i];
		if(s[i-1]=='-')
		{
			now-=a[i];
		  int hh=now;
			int j=i;
			while(j<n&&s[j]!='-')
			{
				hh-=a[j+1];
				j++;
			}
			if(j>=n)break;
			hh+=hz[j+1];
			ans=max(ans,hh);
		}
	}
	cout<<ans<<endl;
}