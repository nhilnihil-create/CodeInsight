#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ll n;
	cin>>n;
	ll arr[n];
	vector<ll> vec;
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	for(ll i=0;i<n;i++)
	{
		if(n%2 == 0)
			if(i%2 != 0)
				vec.insert(vec.begin(), arr[i]);
			else
				vec.push_back(arr[i]);
		else
			if(i%2 == 0)
				vec.insert(vec.begin(), arr[i]);
			else
				vec.push_back(arr[i]);

	}
	for(auto i = vec.begin(); i!=vec.end();i++)
		cout<<*i<<" ";
	return 0;
}