#include<bits/stdc++.h>
using namespace std;
#define N 100005

int n,t,ans;
int a[N];
int mn[N],mx;

int main()
{
	
	cin>>n>>t;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		if(i) mn[i]=min(a[i],mn[i-1]);
		else mn[i]=a[i];
		mx=max(mx,a[i]-mn[i]);
	}
	for(int i=0;i<n;i++)
		if(a[i]-mn[i]==mx) ans++;
	cout<<ans<<'\n';
	
	return 0;
}