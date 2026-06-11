#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar(n) array<int,n>
#define mp make_pair
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,l;
	cin>>n>>l;
	ll a[n];
	for(int i =0; i<n; i++)
		cin>>a[i];
	
	ll x=-1;

	for(int i =0; i<n-1; i++)
		if((a[i]+a[i+1])>=l)
			x = i+1;
	
	if(x ==-1)
		cout<<"Impossible"<<endl;
	else
	{
		cout<<"Possible"<<endl;
		int i =0;
		for(i =1; i<n; i++)
			if(i==x)
				break;
			else
				cout<<i<<endl;
		for(int j =n-1; j>i;j--	)
			cout<<j<<endl;
		cout<<x<<endl;
	}
	return 0;
}