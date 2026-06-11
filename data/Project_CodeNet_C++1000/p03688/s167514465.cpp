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
				ll n;
				cin>>n;
				vector<ll> v(n);
				map<ll,ll> m;
				for(ll i=0;i<n;i++)
					{cin>>v[i];m[v[i]]++;}
				
				sort(v.begin(),v.end());
				if(v[n-1]-v[0]>1)
				{
					cout<<"No";
					exit(0);
				}
				ll c1=0,c2=0;
				if(v[n-1]==v[0])
				{
					if(v[0]+1==n)
						cout<<"Yes";
					else if(n>=(2*v[0]))
						cout<<"Yes";
					else
						cout<<"No";
						
				}
				else
				{
					c1=m[v[0]];
					c2=m[v[n-1]];
					if(c2>=2*(v[n-1]-c1) &&v[n-1]>c1)
						cout<<"Yes";
					else
					{
						cout<<"No";
					}
				}
			}
						
			
