#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <list>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const ll INF = 1LL<<29;
const ll mod = 1e9+7;
#define rep(i,n) for(int (i)=0;(i)<(ll)(n);++(i))
#define repd(i,n,d) for(ll (i)=0;(i)<(ll)(n);(i)+=(d))
#define all(v) (v).begin(), (v).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset((m),(v),sizeof(m))
#define chmin(X,Y) ((X)>(Y)?X=(Y),true:false)
#define chmax(X,Y) ((X)<(Y)?X=(Y),true:false)
#define fst first
#define snd second
#define UNIQUE(x) (x).erase(unique(all(x)),(x).end())
template<class T> ostream &operator<<(ostream &os, const vector<T> &v){int n=v.size();rep(i,n)os<<v[i]<<(i==n-1?"":" ");return os;}
#define N 100010
int par[N],rnk[N];
struct UF {
	
	void init(int n){
		for(int i = 0; i < n; i++){
			par[i] = i;
			rnk[i] = 0;
		}
	}
	
	int find(int x){
		if(par[x] == x){
			return x;
		}else{
			return par[x] = find(par[x]);
		}
	}
	
	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		
		if(rnk[x] < rnk[y]){
			par[x] = y;
		}else{
			par[y] = par[x];
			if(rnk[x] == rnk[y]) rnk[y]++;
		}
	}
	
	bool same(int x, int y){
		return find(x) == find(y);
	}
};

vector<int> g[N];
int d[N], odd[N];
int t[N];

bool dfs(int u, int x){
	t[u] = x;
	for(int &v: g[u]){
		if(!t[v] && dfs(v, x+1)) return true;
		else if((t[v]+x+1)%2) return true;
	}
	return false;
}

int main(){
	ll n, m;
	cin>>n>>m;
	UF uf;
	uf.init(n);
	rep(i, m){
		int u, v;
		cin>>u>>v;
		u--; v--;
		uf.unite(u, v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	rep(i, n){
		int x = uf.find(i);
		d[x]++;
		if(x!=i) continue;
		if(dfs(i, 1)) odd[i] = 1;
	}
	ll vvv = 0, vv = 0, v = 0;
	rep(i, n){
		if(d[i]==1) v++;
		else if(d[i]){
			if(odd[i]) vvv++;
			else vv++;
		}
	}
	cerr<<vvv<<" "<<vv<<" "<<v<<endl;
	ll res = + vv*vv + (vvv+vv)*(vvv+vv) + 2*v*n-v*v;
	cout<<res<<endl;
	return 0;
}
