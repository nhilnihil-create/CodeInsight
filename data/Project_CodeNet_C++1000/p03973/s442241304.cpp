#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI 3.14159265358979
#define EPS 1e-8
#define mod 1000000007
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl "\n"
	 
const ll INF=(ll)2e18;
		
		
const int N=2e5+5;
		
		
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
				
	ll n;
	cin>>n;
	
	vector<ll> v(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
	}			
	
	ll ans=0;
	
	ll pres=1;
	
	for(ll i=0;i<n;i++)
	{
		
		ans+=(v[i]-1)/pres;
		
		if(pres==1 || v[i]==pres)
		{
			pres++;
		}
	}
	cout<<ans;
				
}
