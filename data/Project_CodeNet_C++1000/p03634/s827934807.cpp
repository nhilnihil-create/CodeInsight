#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

const ll INF = 100100100;

struct edge{
	ll to;
	ll cost;
};

ll n;
vector<edge> to[100005];
vector<ll> dist;

void dfs(ll v, ll p, ll d){
	dist[v] = d;
	for(auto nextv: to[v]){
		if(nextv.to == p) continue;
		if(dist[nextv.to] != INF) continue;
		dfs(nextv.to, v, d + nextv.cost);
	}
}

int main(){
	cin >> n;
	dist.resize(n);
	dist.assign(n,INF);
	rep(i,n-1){
		ll a,b,c;
		cin >> a >> b >> c;
		a--;b--;
		to[a].push_back(edge{b,c});
		to[b].push_back(edge{a,c});
	}
	ll q,k;
	cin >> q >> k;
	k--;
	dfs(k,-1,0);
	rep(i,q){
		ll x,y;
		cin >> x >> y;
		x--;y--;
		cout << dist[x] + dist[y] << endl;
	}
    return 0;
}

