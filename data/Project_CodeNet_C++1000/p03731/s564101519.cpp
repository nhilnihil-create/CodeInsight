#include <bits/stdc++.h>
using namespace std; 
int main() 
{
	long long n,t;
	cin>>n>>t;
	long long a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<n;i++)a[i]=a[i]+a[0];
	long long res=0LL;
	for(int i=1;i<n;i++)
	{
		if(a[i]-a[i-1]<t)
		{
			res+=a[i]-a[i-1];
		}
		else
		{
			res+=t;
		}
	}
	res+=t;
	cout<<res;
}