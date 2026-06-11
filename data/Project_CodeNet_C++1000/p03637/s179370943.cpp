#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
	cin>>n;
	ll a[n];
	ll m=0,m2=0,m4=0;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]%4==0)
			m4++;
		else if(a[i]%2==0)
			m2++;
		else
			m++;
			
	}
	if(m2==0)
	{
		if(m-m4<=1)
			cout<<"Yes";
		else
			cout<<"No";
		return 0;
	}
	else
	{
		if(m<=m4)
			cout<<"Yes";
		else
			cout<<"No";
		return 0;
	}
	return 0;
}