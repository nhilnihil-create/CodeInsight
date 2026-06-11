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
	int n,t;
	cin>>n>>t;
	int a[n];
	ll ans = 0;
	ll j = 0;
	for(int i = 0 ;i<n; i++) cin>>a[i];
	for(int i = 0;i <n;i++)
	{
		if(j>a[i])
		{
			ans += t-(j-a[i]);
			j = a[i]+t;
		}
		else
		{
			ans += t;
			j = a[i]+t;
		}
	}
	cout<<ans<<endl;
	return 0;
}