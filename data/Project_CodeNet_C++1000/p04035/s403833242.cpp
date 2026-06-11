			#include <bits/stdc++.h>
			using namespace std;
			#define ll long long
			#define INF 100000000LL
			#define mod 1000000007
			#define pll pair<long,long>
			#define se second
			#define fi first
			#define pb push_back
			#include <ext/pb_ds/assoc_container.hpp>
			#include <ext/pb_ds/tree_policy.hpp>
			using namespace __gnu_pbds;

			typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
			typedef tree<pll,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update>pllordered_set;
			
			
			int main()
			{
				ll n,l;
				cin>>n>>l;
				vector<ll> v(n+1);
				for(ll i=1;i<=n;i++)
					cin>>v[i];
				
				for(ll i=1;i<n;i++)
				{
					if(v[i]+v[i+1]>=l)
					{
						cout<<"Possible\n";
						for(ll j=n-1;j>i;j--)
						{
							cout<<j<<endl;
						}
						for(ll j=1;j<i;j++)
						{
							cout<<j<<endl;
							
						}
						cout<<i;
						exit(0);
					}
				}
				cout<<"Impossible";
			}
						
			
