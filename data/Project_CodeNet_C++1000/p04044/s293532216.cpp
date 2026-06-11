#include<bits/stdc++.h>
using namespace std;

int main()
{
	typedef long long ll; 
	ll n,l;  cin>>n>>l;
	string p;
	vector<string>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++)
	{
		cout<<v[i];
	}
	
	cout<<p<<endl;
	
	return 0;
	
	
}
