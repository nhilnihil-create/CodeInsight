#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main()
{
	ll n,a,t[100005]={},ans[2]={},r=0,k;
	cin>>n;
	map<ll,ll>m;
	for(ll i=0;i<n;i++)
	{
		cin>>a;
		m[a]++;
	}
	vector<ll>v;
	for(auto i=m.begin();i!=m.end();i++) 
	{
		ll s=i->second;
		if(s>=4)r=i->first;
		if(s>=2)v.push_back(i->first);
	}
	if(v.size()<2)k=0;
	else k=v[v.size()-1]*v[v.size()-2];
	cout<<max(r*r,k)<<endl;	
	return 0;
}