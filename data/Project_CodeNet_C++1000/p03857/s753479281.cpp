#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define REP(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, a, b) for(int i=(a); i<(b); ++i)
#define FORR(i, a, b) for(int i=(b)-1; i>=(a); --i)

#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
#define DEBUG_VEC(v) cout<<#v<<":";REP(i, v.size())cout<<' '<<v[i];cout<<'\n'
#define ALL(a) (a).begin(), (a).end()

#define CHMIN(a, b) a=min((a), (b))
#define CHMAX(a, b) a=max((a), (b))

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

struct UnionFind{
	vector<int> par;
	vector<int> rank;

	UnionFind(int n=1){
		init(n);
	}

	// n要素で初期化
	void init(int n=1){
		par.resize(n);
		rank.resize(n);
		REP(i, n){
			par[i]=i;
			rank[i]=0;
		}
	}

	// xの根を求める
	int find(int x){
		if(par[x]==x){
			return x;
		}
		else{
			return par[x]=find(par[x]);
		}
	}

	// xとyが属する集合を併合
	bool unite(int x, int y){
		x=find(x);
		y=find(y);
		if(x==y){
			return false;
		}
		if(rank[x]<rank[y]){
			par[x]=y;
		}
		else{
			par[y]=x;
			if(rank[x]==rank[y]){
				++rank[x];
			}
		}
		return true;
	}

	// xとyが同じ集合に属するか判定
	bool issame(int x, int y){
		return find(x)==find(y);
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, l, p, q, r, s;
	cin>>n>>k>>l;
	UnionFind uf1(n), uf2(n);
	REP(i, k){
		cin>>p>>q;
		--p;
		--q;
		uf1.unite(p, q);
	}
	REP(i, l){
		cin>>r>>s;
		--r;
		--s;
		uf2.unite(r, s);
	}
	pii a[214514], b[214514];
	REP(i, n){
		a[i]=b[i]=pii(uf1.find(i), uf2.find(i));
	}
	sort(a, a+n);
	REP(i, n){
		cout<<upper_bound(a, a+n, b[i])-lower_bound(a, a+n, b[i])<<" \n"[i==n-1];
	}
	return 0;
}
