#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100005],s[100005],cc[100005],ans;
int main()
{
	cin>>n>>a[1];s[1]=cc[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		char c;
		cin>>c>>a[i];
		cc[i]=cc[i-1]+a[i];
		if(c=='-')a[i]*=-1;
		s[i]=s[i-1]+a[i];
	}
	ans=s[n];
	for(int i=2;i<=n;i++)if(a[i]<0)
	{
		long long tt=a[i]*2;
		for(int j=i+1;j<=n&&a[j]>0;j++)tt-=a[j]*2;
		ans=max(ans,s[i-1]+tt+cc[n]-cc[i-1]);
	}
	cout<<ans<<endl;
	return 0;
}