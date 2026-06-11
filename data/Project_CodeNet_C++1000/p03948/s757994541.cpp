#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[100005],mx[100005];
int profits,ans=0;
int main()
{
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	mx[n]=a[n];
	for(int i=n-1;i>=0;i--)
	{
		mx[i]=max(mx[i+1],a[i]);
	}
	for(int i=1;i<=n;++i)
	{
		if(profits<mx[i]-a[i])
		{
			profits=mx[i]-a[i];
			ans=1;
		}
		else if(profits==mx[i]-a[i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}