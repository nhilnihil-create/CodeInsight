#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define X first
#define Y second
#define pb push_back
#define max_el(x) max_element(x.begin(),x.end())-x.begin()
#define min_el(x) min_element(x.begin(),x.end())-x.begin()
#define mp make_pair
#define endl '\n'
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
// DONT USE MEMSET, USE VECTORS

vector<pair<int,int> > g[5000];
vector<int> pred[5000];
int n,m;
set<pair<int,int> > st;

void dijk(int s){
	set<pair<int,int> > heap;
	vector<int> dist(n+1,1e8);
	dist[s] = 0;
	heap.insert(mp(0,s));
	while(!heap.empty()){
		int u = heap.begin()->Y;
		heap.erase(heap.begin());
		for(auto x:g[u]){
			int v = x.X;
			int w = x.Y;
			if(dist[v] > dist[u] + w){
				heap.erase(mp(dist[v],v));
				dist[v] = dist[u] + w;
				pred[v].clear();
				pred[v].pb(u);
				heap.insert(mp(dist[v],v));
			}
			if(dist[v] == dist[u] + w){
				pred[v].pb(u);
			}
		}
	}
}

void solve(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].pb(mp(v,w));
		g[v].pb(mp(u,w));
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			pred[j].clear();
		}
		dijk(i);

		for(int j=1;j<=n;j++){
			for(int k:pred[j]){
				// cout<<i<<" "<<j<<" "<<k<<endl;
				st.insert({min(j,k), max(j,k)});
			}
		}
	}
	// for(auto x:st){
	// 	cout<<x.X<<" "<<x.Y<<endl;
	// }

	cout<<m-(int)st.size()<<endl;
}

int main(){
	fastread;
	int t = 1;
	// cin>>t;
	for(int i=1;i<=t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
