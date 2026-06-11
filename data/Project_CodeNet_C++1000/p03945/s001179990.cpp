#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007

void solve()
{
	string s;
	cin>>s;
	ll ans=0;
	for(ll i=1;i<s.size();i++)
		if(s[i]!=s[i-1])
			ans++;
	cout<<ans;
	
	return;
}

int main()
{
	fast;
	ll q=1;
	// cin>>q;
	while(q--)
		solve();
	return 0;
}

