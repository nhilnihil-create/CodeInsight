#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
void solve()
{
	string s;
	cin>>s;
	vector<ll> a(26,0);
	for(ll i=0;i<s.size();i++)
		a[s[i]-'a']++;
	for(ll i=0;i<26;i++)
	{
		if(a[i]==0)
		{
			cout<<char(i+'a');
			return;
		}
	}
	cout<<"None";
	return;
}


int main()
{
	fast;
	ll q;
	q=1;
	// cin>>q;
	while(q--)
	{
		solve();
	}
	return 0;
}
