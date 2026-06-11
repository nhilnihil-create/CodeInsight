#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x;
	cin>>n>>x;
	int a[n+1]={0};
	for(int i=1;i<=n;i++)cin>>a[i];
	long long ans=0LL;
	for(int i=1;i<=n;i++)
	{
		if(a[i]+a[i-1]>x)
		{
			ans+=a[i]+a[i-1]-x;
			a[i]-=(a[i]+a[i-1]-x);
		}
	}
	cout<<ans;
}