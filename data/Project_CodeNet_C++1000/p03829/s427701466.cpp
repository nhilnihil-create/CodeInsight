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
	ll n,a2,b;
	cin>>n>>a2>>b;
	int a[n];
	for(int i =0 ;i<n;i++)
		cin>>a[i];

	ll ans = 0;
	for(int i = 0 ;i<n-1;i++)
	{
		a[i]= -a[i]+a[i+1];
		ll h = a[i]*a2;
		ans += min(h,b);
	}
	cout<<ans<<endl;
	return 0;
}