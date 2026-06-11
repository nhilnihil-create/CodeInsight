#include <bits/stdc++.h>
#define rep(i, a) for (int i = (int)0; i < (int)a; ++i)
#define rrep(i, a) for (int i = (int)a - 1; i >= 0; --i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define RREP(i, a, b) for (int i = (int)a - 1; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using ll = long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;

template <class T>
inline bool chmin(T &a, T b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}

ll gcd(ll n, ll m)
{
	ll tmp;
	while (m != 0)
	{
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}

ll lcm(ll n, ll m)
{
	return abs(n) / gcd(n, m) * abs(m); //gl=xy
}

using namespace std;

ll h,w;

//グラフのテンプレート
template<typename T>
struct edge {
	int from, to;
	T cost;

    edge(int to,T cost):from(0),to(to),cost(cost){}
	edge(int from, int to, T cost) :from(from), to(to), cost(cost) {}
};

//Union-Findtree
struct UF {
	vector<int>par;//親
	vector<int>Rank;//木の深さ

    UF(int n){init(n);}

	//初期化
	void init(int n) {
		par.resize(n); Rank.resize(n);
		for (int i = 0; i < n; i++) {
			par[i]= i;
			Rank[i] = 0;
		}
	}

	//木の根を求める
	int find(int x) {
		if (par[x] == x) {
			return x;
		}
		else {
			return par[x] = find(par[x]);
		}
	}

	//xとyの属する集合を併合
	bool unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)return false;//すでに同じ集合に属している

		if (Rank[x] < Rank[y]) {//高さが小さい方を下に
			par[x] = y;
		}
		else {
			par[y] = x;
			if (Rank[x] == Rank[y])Rank[x]++;//同じだとrankが変わらないままになるので増やす（それ以外は大きい方のrankが採用される）
		}
        return true;
	}

	//xとyが同じ集合に属するかを判定
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

template<typename T>
ll kruskal(vector<edge<T>> &e,int v){//クラスカル法(最小全域木における最小の重みを判定)
    //v頂点からなる重み付き辺集合e
    sort(e.begin(),e.end(),[](const edge<T> &e1,const edge<T> &e2){
        return e1.cost.first<e2.cost.first;//ラムダ式を使ってedge.costが小さい順にソート
    });
    UF tree(v);
    ll sum=0;
		ll hh=h+1,ww=w+1;
    for(auto &es:e){
        if(tree.unite(es.from,es.to)){
					if(es.cost.second==1){
						sum+=es.cost.first*hh;
						--ww;
					}
					else {
						sum+=es.cost.first*ww;
						--hh;
					}
				}
    }
    return sum;
}

using P=pair<ll,int>;
void solve()
{
	cin>>w>>h;
	ll ans=0;
  vector<ll>p(w),q(h);
  rep(i,w)cin>>p[i];
  rep(i,h)cin>>q[i];
  vector<edge<P>>e;
	rep(i,w)e.emplace_back(i,i+1,P{p[i],1});
	rep(i,h)e.emplace_back(i+w,i+w+1,P{q[i],0});
	ans=kruskal<P>(e,h+w+1);
	cout<<ans<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
