		#include <bits/stdc++.h>
		using namespace std;
		typedef long long ll;
		#define PI 3.14159265358979
		#define EPS 1e-8
		#define mod  998244353
		#define fi first
		#define se second
		#define mp make_pair
		#define pb push_back
		#define endl "\n"
			 
		const ll INF=1e15;	
		const int N=2e5+50;
		 

		 
		long long binpow(long long a, long long b, long long m) {
			a %= m;
			long long res = 1;
			while (b > 0) {
				if (b & 1)
					res = res * a % m;
				a = a * a % m;
				b >>= 1;
			}
			return res;
		}
		
		ll modinverse(ll a,ll m)
		{
			return binpow(a,m-2,m);
		}
		
			
		
		
		int main()
		{
			ios_base::sync_with_stdio(false);
			cin.tie(NULL);cout.tie(0);
		
					
			ll n;
			cin>>n;
			
			vector<ll> v(n+1,0),v1(n+1,0);
			
			for(ll i=1;i<=n;i++)
			{
				cin>>v[i];
				
				v[i]+=v[i-1];
				v1[i]=v[i];
			}
			
			ll ans1=0,ans2=0;
			ll val1=0,val2=0;
			
			
			for(ll i=1;i<=n;i++)
			{
				
				v[i]+=val1;
				v1[i]+=val2;
				
				
				
				if(i%2==1)
				{
					
					if(v[i]<=0)
					{
						ans1+=(1-v[i]);
						val1+=(1-v[i]);
					}
					if(v1[i]>=0)
					{
						ans2+=(v1[i]+1);
						val2-=(v1[i]+1);
					}
				}
				else
				{
					if(v1[i]<=0)
					{
						
						
						ans2+=(1-v1[i]);
						val2+=(1-v1[i]);
					}
					if(v[i]>=0)
					{
						ans1+=(v[i]+1);
						val1-=(v[i]+1);
					}
				}
			}
		
			cout<<min(ans1,ans2);
			
			
			
			
			
		}
			
			
		
