#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 const ll inf=1e9+7;

int main()
{
    fast;
    

	ll n,x;
	cin>>n>>x;
	
	ll a[n+1];
	
	a[0]=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	ll ans=0;
	
	for(ll i=1;i<=n;i++)
	{
		if(a[i]+a[i-1]>x)
		{
			ll delta;
			delta=a[i]+a[i-1]-x;
			
			
			if(delta>a[i])a[i]=0,delta-=a[i],a[i-1]-=delta;
			else 
			a[i]-=delta;
			
			ans+=delta;
			
		}
	}
	


cout<<ans;
}



		
	
	
	
	
