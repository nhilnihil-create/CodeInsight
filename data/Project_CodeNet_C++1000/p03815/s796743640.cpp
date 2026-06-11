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
	ll x;
	cin>>x;
	ll ans = (x/11)*2;
	x %= 11;
	if(x ==0)
	{
		cout<<ans<<endl;
		return 0;
	}
	if(ans&1)
	{
		if(x>5) ans+= 2;
		else ans++;
	}
	else
	{
		if(x>6) ans+= 2;
		else ans++;
	}
	cout<<ans<<endl;
	return 0;
}