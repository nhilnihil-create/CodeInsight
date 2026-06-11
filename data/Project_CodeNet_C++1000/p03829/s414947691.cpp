#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll MOD=1e9+7;

void solve()
{
	ll n,a,b,ans=0,k=0;;
	cin>>n>>a>>b;
	ll c[n];
	for(ll i=0;i<n;i++)
		cin>>c[i];
	for(ll i=1;i<n;i++)
	{
		// cout<<(c[i]-c[i-1])*a<<" "<<ans<<endl;
		ans+=min(b,(c[i]-c[i-1])*a);
	}
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
