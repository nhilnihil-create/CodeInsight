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
	for(ll i=0;i<s.size();i++)
	{
		if(i%2==0)
			cout<<s[i];
	}
	return;
}
int main()
{
	fast;
	int q;
	q=1;
	// cin>>q;
	while(q--)
	{
		solve();
	}
	return 0;
}