#include <bits/stdc++.h>

#define ll long long 

using namespace std;

const int N = 2e5+5,mod=1e9+7;

int main() {
	int n;
	cin>>n;
	ll ans=0,sum=0;
	vector<int> v;
	for (ll i = 0; i < n; ++i)
	{
		ll x;
		cin>>x;
		sum+=x;
		if(x==0){
			ans+=sum/2;
			sum=0;
		}
	}
	ans+=sum/2;
	cout<<ans;
}