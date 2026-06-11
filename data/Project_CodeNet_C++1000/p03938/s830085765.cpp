		#include <bits/stdc++.h>
		using namespace std;
		#define ll int
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
					ios_base::sync_with_stdio(false);
					cin.tie(NULL);
					
					ll n;
					cin>>n;
					vector<ll> p(n+2);
					for(ll i=0;i<n;i++)
						cin>>p[i];
						
					vector<ll> a(n+2);
					vector<ll> b(n+2);
					for(ll i=1;i<=n;i++)
					{
						a[i]=i;
						b[i]=n-i+1;
					}
					vector<ll> c1(n+2,0);
					vector<ll> c2(n+2,0);
					ll cnt=1;
					for(ll i=0;i<n;i++)
					{
						c2[0]+=cnt;
						c2[p[i]+1]-=cnt;
						c1[p[i]]+=cnt;
						c1[n+1]-=cnt;
						cnt++;
					}
					for(ll i=1;i<=(n+1);i++)
					{
						c1[i]+=c1[i-1];
						c2[i]+=c2[i-1];
					}
					for(ll i=1;i<=n;i++)
					{
						cout<<a[i]+c1[i]<<" ";
					}
					cout<<endl;
					for(ll i=1;i<=n;i++)
					{
						cout<<b[i]+c2[i]<<" ";
					}
					
					
					
		}
