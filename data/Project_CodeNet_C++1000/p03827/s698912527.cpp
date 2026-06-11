#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll MOD=1e9+7;

void solve()
{
	ll n,ans=0,k=0;;
	cin>>n;
	string s;
	cin>>s;
	for(ll i=0;i<n;i++)
	{
		if(s[i]=='I')
			ans++;
		else
			ans--;
		k=max(ans,k);
	}
	cout<<k;;	
	return;
}
int main()
{
        fast;
        ll q;
        q=1;
        // cin>>q;
        while(q--)
        	solve();
        
        return 0;
}
