#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int a[n];
	map<ll,ll> m;
	for(int i= 0; i<n; i++)
	{
		cin>>a[i];
		m[a[i]]++;
	}
	ll l=0,r=0;
	for(auto it:m)
	{
		ll y = it.first;
		ll h = it.second;
		if(h>=4)
		{
			l = y;r = y;
		}
		else if(h>=2)
		{
			if(r<l)
				r = y;
			else
				l = y;
		}
	}
	cout<<l*r<<endl;
	return 0;
}