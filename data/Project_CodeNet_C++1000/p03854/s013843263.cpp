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
	ll n=s.size();
	reverse(s.begin(),s.end());
	for(ll i=0;i<n;)
	{
		if(n-i>=5)
		{
			if(s.substr(i,5)=="maerd" || s.substr(i,5)=="esare")
			{
				i+=5;
				continue;
			}
		}
		if(n-i>=6)
		{
			if(s.substr(i,6)=="resare")
			{
				i+=6;
				continue;
			}
		}
		if(n-i>=7)
		{
			if(s.substr(i,7)=="remaerd")
			{
				i+=7;
				continue;
			}
		}
		cout<<"NO";
		return;
	}
	cout<<"YES";
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

