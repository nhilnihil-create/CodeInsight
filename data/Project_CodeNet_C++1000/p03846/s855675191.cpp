#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll MOD=1e9+7;

void solve()
{
	ll n;
	cin>>n;
	ll a[n];
	
	for(ll i=0;i<n;i++)
		cin>>a[i];
	vector<ll> cnt(n,0);
	if(n%2==0)
	{
		for(ll i=0;i<n;i++)
		{
			cnt[a[i]]++;
			if (a[i]>=n || a[i]%2==0 || cnt[a[i]]>2) 
			{
				cout<<0<<endl;
				return;
			}
		}
	}
	else
	{
		for (ll i=0;i<n;i++) 
		{
			cnt[a[i]]++;
			if (a[i]>=n || a[i]%2==1 || cnt[0]>1 || cnt[a[i]]>2) 
			{
				cout<<0<<endl;
				return;
			}
		}
	}
	ll ans=1;
		for(ll i=0;i<n/2;i++)
			ans*=2,ans%=MOD;
		cout<<ans;
	
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