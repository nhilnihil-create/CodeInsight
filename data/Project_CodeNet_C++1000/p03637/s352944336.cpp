#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007


void solve()
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
		return;
	}
	else
	{
		if(m<=m4)
			cout<<"Yes";
		else
			cout<<"No";
		return;
	}
	return;
}
int main()
{
	fast;
	int q;
	q=1;
	// cin>>q;
	while(q--)
	{
		solve();
	}
	return 0;
}