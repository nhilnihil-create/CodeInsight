#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	ll sum=0;
	for(ll i=n-1;i>=0;i--)
	{
		sum+=a[i];
	}
	if(sum%10==0)
	{
		for(ll i=0;i<n;i++)
		{
			if((sum-a[i])%10!=0)
			{
				cout<<sum-a[i];return 0;
			}
		}
		cout<<0;return 0;
	}
	else cout<<sum;
}