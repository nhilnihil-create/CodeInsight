#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF INT_MAX/3

struct UnionFind{
  vector<int> v;
  UnionFind(int n) : v(n, -1) {}
  void init(){ for(int i = 0;i < v.size();i++)v[i]=-1; }
  int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (-v[x] < -v[y]) swap(x, y);
    v[x] += v[y]; v[y] = x;
    return true;
  }
  bool root(int x) { return v[x] < 0; }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -v[find(x)]; }
};

ll n,m;
ll cnt[3];
bool used[202020];
ll c[202020];
vector<ll> g[202020];

bool dfs(ll v,ll nc){
  c[v]=nc;
  for(ll nv : g[v]){
    if(c[nv]==-1&&!dfs(nv,1-nc))return false;
    else{
      if(c[nv]==nc)return false;
    }
  }
  return true;
}

int main(){
	cin>>n>>m;
  UnionFind uf(n);
  rep(i,m){
    ll a,b;
    cin>>a>>b;
    a--; b--;
    uf.unite(a,b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  memset(c,-1,sizeof(c));
  rep(i,n){
    if(used[uf.find(i)])continue;
    used[uf.find(i)]=true;
    if(uf.size(i)==1)cnt[2]++;
    else{
      bool nibu=dfs(i,0);
      cnt[nibu]++;
    }
  }
  ll res=cnt[2]*n*2-cnt[2]*cnt[2];
  res+=(cnt[0]+cnt[1])*(cnt[0]+cnt[1]);
  res+=cnt[1]*cnt[1];
  cout<<res<<endl;
	return 0;
}
