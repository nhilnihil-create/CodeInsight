#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define INF 1e15
int qe,k;
vector<pair<ll,ll> > adj[100005];
vector<ll> dist(100005, INF); 

void shortestPath() 
{ 
    priority_queue< pair<ll,ll>, vector <pair<ll,ll>> , greater<pair<ll,ll>> > pq; 
    pq.push(make_pair(0, k)); 
    dist[k] = 0; 
    while (!pq.empty()) 
    { 
        ll u = pq.top().second; 
        pq.pop(); 
        for (auto i= adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            ll v = (*i).first; 
            ll weight = (*i).second; 
  
            //  If there is shorted path to v through u. 
            if (dist[v] > dist[u] + weight) 
            { 
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 
} 


int main()
{
	ll t=1;while(t--){
	ll n,m;cin>>n;
	for(ll i=1;i<=n-1;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	cin>>qe>>k;
	shortestPath();
	while(qe--)
	{
		ll a,b;cin>>a>>b;
		cout<<dist[a]+dist[b]<<endl;
	}
     
	
	




	
}}