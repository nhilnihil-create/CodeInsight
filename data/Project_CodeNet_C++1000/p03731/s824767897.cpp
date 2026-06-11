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
	for(int i = 0; i<n;i++) cin>>a[i];
	for(int i = 1; i<n; i++)
	{
		ans += min(t,a[i]-a[i-1]);
	}
	cout<<ans+t<<endl;
	return 0;
}