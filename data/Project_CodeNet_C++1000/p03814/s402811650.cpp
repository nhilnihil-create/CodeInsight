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
	ll i=0,j=s.size()-1;
	for(;i<s.size();i++)
	{
		if(s[i]=='A')
			break;
	}
	for(;j>=0;j--)
	{
		if(s[j]=='Z')
			break;
	}
	cout<<max(0ll,j-i+1);
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

