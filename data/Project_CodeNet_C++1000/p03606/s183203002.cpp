#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define pb push_back
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	ll ans = 0;
	while(t--)
	{
		int l,r;cin>>l>>r;
		ans += r-l+1;
	}
	cout<<ans<<endl;
	return 0;
}