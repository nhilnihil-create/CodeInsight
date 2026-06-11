#include<iostream>
#include <cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=998244353 ;



struct UnionFind{
	vector<int> par,siz;
	UnionFind(int N): par(N), siz(N){
		rep(i, N){
			par[i] = i; siz[i] = 1;
		}
	}
	int root(int x){
		if(par[x]==x) return x;
		else return root(par[x]);
	}
	void unite(int x, int y){
		x=root(x); y=root(y);
		if(x==y) return;
		if(siz[x] < siz[y]) swap(x, y);
		par[y] = x;
		siz[x] += siz[y];
	}
	bool same(int x, int y){
		return root(x)==root(y);
	}
	int size(int x){
		return siz[root(x)];
	}
};


int Color[100000] = {};
vector<int> to[100000];
 
void init(int X) {
	for (int i = 0; i < X; i++) Color[i] = -1;
}
 
bool DFS(int X, int C) {
	Color[X] = C;
	for (int Y : to[X]) {
		if (Color[Y] == -1) {
			if (!DFS(Y, 1 - C)) return false;
		}
		else if (Color[Y] == Color[X]) return false;
	}
	return true;
}

int main(){
  int N, M; cin >> N >> M;
  UnionFind uf(N); init(N);
  rep(i, M){
    int u, v; cin >> u >> v; u--; v--;
    uf.unite(u, v);
    to[u].push_back(v); to[v].push_back(u);
  }
  int cnt = 0, s=0;
  rep(i, N){
    if(uf.root(i)!=i) continue;
    if(uf.size(i)==1) continue;
    if(DFS(i, 0)){
      cnt++;
      s+=uf.size(i);
    }
  }
  init(N);
  //cout << s << endl;
  //cout << cnt << endl;
  ll ans = 0; ans+=((ll)cnt*cnt*2);
  //cout << ans << endl;
  rep(i, N){
    if(uf.root(i)!=i) continue;
    if(uf.size(i)==1) continue;
    if(!(DFS(i, 0))){
      if(uf.size(i)!=1) ans+=((ll)2*cnt+1);
      cnt++;
      s+=uf.size(i);
      //cout << uf.size(i) << endl;
    }
  }
  //cout << cnt << endl;
  rep(i, N){
    if(uf.size(i)==1){
      ans+=(ll)(2*s+1); s++;
    }
  }
  //cout << s << endl;
  cout << ans << endl;
}