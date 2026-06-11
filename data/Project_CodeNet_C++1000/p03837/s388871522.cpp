#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 103;

const int inf = 1e9;

int n, m;
set<pair<int,int>> g[maxn];

struct edge {
    int u,v,w;
};


vector<edge> edges;

int dist[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);


    cin>>n>>m;

    for (int i=0; i<n; i++) {
	for (int j=0; j<n; j++) {
	    dist[i][j]=inf;
	    if (i==j) dist[i][j]=0;
	}
    }

    
    for (int i=0; i<m; i++) {
	int u,v,w; cin>>u>>v>>w;
	--u; --v;
	g[u].insert({w,v});
	g[v].insert({w,u});
	dist[u][v]=dist[v][u]=w;
	edges.push_back(edge{u,v,w});
    }

    

    for (int k=0; k<n; k++) {
	for (int i=0; i<n; i++) {
	    for (int j=0; j<n; j++) {
		dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	    }
	}
    }


    int res = m;

    for (auto ed: edges) {
	int u=ed.u;
	int v=ed.v;
	int w=ed.w;
	bool shortest = false;
	for (int i=0; i<n; i++) {
	    if (dist[i][u]+w == dist[i][v]) {
		shortest=true;
	    }
	}
	if (shortest) {
	    res--;
	}
    }


    cout<<res<<endl;

    return 0;
}
