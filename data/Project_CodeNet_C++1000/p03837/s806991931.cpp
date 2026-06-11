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


		ll vis[100050][3];
		vector<ll> g1[100050];

		int main()
		{
					ios_base::sync_with_stdio(false);
					cin.tie(NULL);
					ll n,m;
					cin>>n>>m;
					ll dist[105][105];
					vector<tuple<ll,ll,ll> > edge;
					for(ll i=0;i<=n;i++)
					{
						for(ll j=0;j<=n;j++)
							dist[i][j]=INF;
					}
					for(ll i=0;i<=n;i++)
						dist[i][i]=0;
					for(ll i=0;i<m;i++)
					{
						ll u,v,w;
						cin>>u>>v>>w;
					//cout<<dist[u][v]<<" "<<dist[v][u]<<endl;
						dist[u][v]=min(dist[u][v],w);
						dist[v][u]=min(dist[v][u],w);
						edge.pb(make_tuple(u,v,w));
					}
					
					for(ll k=1;k<=n;k++)
					{
						for(ll i=1;i<=n;i++)
						{
							for(ll j=1;j<=n;j++)
							{
								if(dist[i][k]+dist[k][j]<dist[i][j])
								{
									dist[i][j]=dist[i][k]+dist[k][j];
								}
								
							}
						}
						
					}
					ll ans=0;
					for(auto i:edge)
					{
						ll u=get<0>(i);
						ll v=get<1>(i);
						ll w=get<2>(i);
						
						if(dist[u][v]<w)
						{
						//	cout<<u<<" "<<v<<" "<<dist[u][v]<<endl;
							ans++;
						}
					}
					
					cout<<ans;
					
					
		}
