#include <bits/stdc++.h>

using namespace std;

#define rep(i,m,n) for(int (i)=(int)(m);i<(int)(n);i++)
#define REP(i,n) rep(i,0,n)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long
#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
#define en '\n'
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
typedef pair<ll, ll> P;
const long long INF = 1LL << 60;
const int INF_INT = 1 << 25;
const long long MOD = (ll) 1e9 + 7;
typedef vector<ll> Array;
typedef vector<Array> Matrix;
const int loose = 0;
const int tight = 1;


template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

struct Edge {
	ll to, cap, rev;
	Edge(ll _to, ll _cap, ll _rev) {
	to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	ll n,m;
	cin>>n>>m;

	Graph g(n);
	Array l;//左端から広げる
	Array r;//右端から広げる
	Array used(n,false);

	//最初の一辺からパスを広げてく
	ll a,b;
	cin>>a>>b;
	a--;b--;
	add_edge(g,a,b,1,true,1);
	l.push_back(a);
	r.push_back(b);
	used[a]=true;
	used[b]=true;

	REP(i,m-1){
		cin>>a>>b;
		a--;b--;
		add_edge(g,a,b,1,true,1);
	}

	bool flag_l=true;
	bool flag_r=true;

	while(flag_l){
		int v = l[l.size()-1];
		for(auto e:g[v]){
			if(!used[e.to]){
				l.push_back(e.to);
				used[e.to]=true;
				break;
			}
		}
		if(v==l[l.size()-1]) flag_l=false;
	}
	
	while(flag_r){
		int v = r[r.size()-1];
		for(auto e:g[v]){
			if(!used[e.to]){
				r.push_back(e.to);
				used[e.to]=true;
				break;
			}
		}
		if(v==r[r.size()-1]) flag_r=false;
	}

	cout<<l.size()+r.size()<<en;
	reverse(all(l));
	for(auto v: l){
		cout<<v+1<<" ";
	}
	for(auto v:r){
		cout<<v+1<<" ";
	}

	cout<<en;

    return 0;
}