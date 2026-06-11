#include<bits/stdc++.h>
using namespace std;
#define nl '\n' 
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int


int main()
{
	fast;
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	int c=0;
	vector<int>v;
	v.push_back(a[0]);
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i-1])
			v.push_back(a[i]);
	}
	for(int i=1;i<v.size()-1;i++)
	{
		if((v[i]>=v[i+1] && v[i]>v[i-1])|| (v[i]>v[i+1] && v[i]>=v[i-1]) )
		{
			c++;
			i++;
		}
		else if((v[i]<=v[i+1] && v[i]<v[i-1])|| (v[i]<v[i+1] && v[i]<=v[i-1]) )
		{
			c++;
			i++;
		}
	}
	cout<<c+1<<nl;
}