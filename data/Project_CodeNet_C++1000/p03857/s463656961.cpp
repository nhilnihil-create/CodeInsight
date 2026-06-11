//#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
//template <class c, class cmp = less<c> > using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) {os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {return os << "(" << P.first << "," << P.second << ")";}
template <typename T,typename U>pair<T,U> operator+(const pair<T,U> & l,const std::pair<T,U> & r) { return {l.first+r.first,l.second+r.second};}
typedef long long int ll;
const ll mod =1e9+7;
const int maxn = 300002;
#define endl '\n'
#define int ll
#define ld long double
#define all(x) (x).begin(),(x).end()
vector<int> gl[maxn],gr[maxn];
int vis[maxn],ans[maxn];
vector<int> s;
void dfs(int u){
  vis[u] = true;
  s.push_back(u);
  for(auto v:gl[u]){
    if(!vis[v]) dfs(v);
  }
}
void dfs1(int u){
  vis[u] = true;
  s.push_back(u);
  for(auto v:gr[u]){
    if(!vis[v]) dfs1(v);
  }
}
 struct DSU{
    vector<ll>par,sz;
    DSU(ll n)
    {
      par.resize(n);
      sz = vector<ll>(n,1);
      iota(par.begin(),par.end(),0);
    }
    ll find(ll x){
        if(x==par[x])
          return x;
        return par[x] = find(par[x]);
    }
    void unite(ll a, ll b){
        a = find(a);
        b = find(b);
        if(a==b)
          return ;
        if(sz[a]<sz[b])
          swap(a,b);
        par[b] = a;
        sz[a]+=sz[b];
        return ;
    }

  };
int id = 0;
map<int,int> m;
void solve(){
  id++;
  for(auto u:s){
    m[u] = id;
  }
}

void solve1(){

  map<int,int> h;
  for(auto u:s){
    h[m[u]]++;
  }
  for(auto u:s) ans[u] = h[m[u]];
}
int32_t main()
{ 
   IOS


  int n,k,l;
  cin >> n >> k >> l;
  for(int i = 0;i<k;i++){
    int u,v;
    cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  for(int i  = 0;i<l;i++){
    int u, v;
    cin >> u >> v;
    gl[u].push_back(v);
    gl[v].push_back(u);
  }

  for(int i = 1;i<=n;i++){
    if(!vis[i]){
      s.clear();
      dfs(i);
      solve();
    }
  }

  memset(vis,0,sizeof(vis));
  for(int i = 1;i<=n;i++){
    if(!vis[i]){
      s.clear();
      dfs1(i);
      solve1();
    }
  }



  for(int i = 1;i<=n;i++)  cout<< ans[i] <<" ";
  


  
  
    
    




  
}