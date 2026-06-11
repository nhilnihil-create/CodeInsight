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
	if(s[0]==s[s.size()-1])
	{
		if(s.size()%2==0)
			cout<<"First";
		else
			cout<<"Second";
	}
	else
	{
		if(s.size()%2!=0)
			cout<<"First";
		else
			cout<<"Second";
	}
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

