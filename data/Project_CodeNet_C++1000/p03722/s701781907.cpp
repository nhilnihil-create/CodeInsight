#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

template<typename T>
struct BellmanFord{
	struct Edge{
		int  from,to; ll cost;
		Edge(){}
		Edge(int from,int to,ll cost):from(from),to(to),cost(cost){}
	};

	int n;
	vector<vector<int> >G;
	vector<int> used,reach;
	BellmanFord(int n):n(n),G(n),used(n,0),reach(n,0){}

	vector<Edge> es;
	void add_edge(int from,int to,ll cost){
		es.push_back(Edge(from,to,cost));
		G[from].push_back(to);
	}

	void dfs(int v){
		if(used[v])return ;
		used[v]=1;
		for(int u:G[v]){
			dfs(u);
		}
	}
	ll build(int from,int to,int &neg_loop){
		for(int i=0;i<n;i++){
			fill(used.begin(),used.end(),0);
			dfs(i);
			reach[i]=used[to];
		}
		vector<ll> ds(n,1e18);
		ds[from]=0;
		for(int i=0;i<n;i++){
			bool update=0;
			for(auto e:es){
				if(!reach[e.from]||!reach[e.to]||ds[e.from]==1e18) continue;
				if(ds[e.to]>ds[e.from]+e.cost){
					ds[e.to]=ds[e.from]+e.cost;
					update=1;
				}
			}
			if(!update)break;
			if(i==n-1){
				neg_loop=1;
				return 1e18;
			}
		}
		neg_loop=0;
		return ds[to];
	}
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n, m;
    cin >> n >> m;
    BellmanFord<ll> bf(n);
    rep(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        bf.add_edge(a, b, -c);
    }
    int neg;
    ll dist = bf.build(0, n - 1, neg);
    if (neg) cout << "inf" << endl;
    else cout << -dist << endl;
    return 0;
}
