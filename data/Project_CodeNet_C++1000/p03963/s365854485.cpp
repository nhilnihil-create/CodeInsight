#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n,k;cin>>n>>k;
	ll res=1LL;
	for(ll i=2;i<=n;i++)
	res*=(k-1LL);
	res*=k;
	cout<<res;
}