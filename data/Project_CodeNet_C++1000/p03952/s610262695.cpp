
		#include <bits/stdc++.h>
		using namespace std;
		
		typedef long long ll;
		#define pi 3.14159265 
		#define EPS 1e-8
		
		#define mod 998244353
		#define fi first
		#define se second
		#define mp make_pair
		#define pb push_back
		#define endl "\n"

		const ll INF=(ll)2e18;
	
		
		int main()
		{
			 ios_base::sync_with_stdio(false);
			 cin.tie(NULL);
			
			ll n,x;
			cin>>n>>x;
			if(x==1 || x==(2*n-1))
			{
				cout<<"No";
				exit(0);
			}
			vector<ll> v(2*n,0);
			v[n]=x;
			v[n+1]=x+1;
			v[n-1]=x-1;
			vector<ll> vis(2*n,0);
			vis[x]=vis[x+1]=vis[x-1]=1;
			if(x+2<=(2*n-1))
			{
				v[n-2]=x+2;
				vis[x+2]=1;
			}
			if((x-2)>=1)
			{
				v[n+2]=x-2;
				vis[x-2]=1;
			
			}
			ll j=1;
			for(ll i=1;i<2*n;i++)
			{
				if(v[i])
					continue;
				while(vis[j])
				{
					j++;
				}
				vis[j]=1;
				v[i]=j;
			}
			cout<<"Yes\n";
			for(ll i=1;i<2*n;i++)
			{
				cout<<v[i]<<endl;
			}
		}
						
					 
				 
