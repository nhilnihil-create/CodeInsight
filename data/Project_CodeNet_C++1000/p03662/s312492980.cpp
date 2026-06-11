#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define db long double
#define ii pair<int,int>
#define vi vector<int>
#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define FN(i, n) for (int i = 0; i < (int)(n); ++i)
#define FEN(i,n) for (int i = 1;i <= (int)(n); ++i)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repv(i,a,b) for(int i=b-1;i>=a;i--)
#define SET(A, val) memset(A, val, sizeof(A))
typedef tree<int ,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set ;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
const int N=100005;
vi v[N];
int p[N],child[N];
bool mark[N];
void dfs(int u,int par)
{
  p[u]=par;
  for(int v1:v[u])
    if(v1!=par) 
      dfs(v1,u);
}
void dfs2(int u,int root,int par=-1)
{
  child[root]++;
  for(int v1:v[u])
    if(!mark[v1] && v1!=par)
      dfs2(v1,root,u);
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(NULL) ; cout.tie(NULL) ;
  int n,x,y;
  cin>>n;
  rep(i,1,n)
    {
      cin>>x>>y;
      v[x].pb(y); v[y].pb(x);
    }
  dfs(1,-1);
  vi path;
  int curr=n;
  while(curr!=-1)
    {
      path.pb(curr);
      mark[curr]=true;
      curr=p[curr];
    }
  reverse(all(path));
  rep(i,1,n+1)
    if(mark[i]) dfs2(i,i);
  int sum1=0,sum2=0;
  rep(i,0,sz(path))
    {
      if(i<(sz(path)+1)/2) sum1+=child[path[i]];
      else sum2+=child[path[i]];
    }
  if(sum1<=sum2) cout<<"Snuke"<<endl;
  else cout<<"Fennec"<<endl;
  return 0 ;
}
