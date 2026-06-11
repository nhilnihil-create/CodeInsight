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
const int N=305,inf=1e9+10;
int a[N][N],d[N][N];
bool mark[N];
int n;
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(NULL) ; cout.tie(NULL) ;
  cin>>n;
  rep(i,1,n+1)
    rep(j,1,n+1) cin>>a[i][j],d[i][j]=a[i][j];
  rep(k,1,n+1)
    rep(i,1,n+1) rep(j,1,n+1) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
  bool ok=true;
  rep(i,1,n+1) rep(j,1,n+1) ok&=(a[i][j]==d[i][j]);
  if(!ok)
    {
      cout<<-1<<endl;
      return 0;
    }
  ll ans=0;
  rep(i,1,n+1)
    rep(j,i+1,n+1)
    {
      bool ok=true;
      rep(k,1,n+1)
	if(a[i][k]+a[k][j]==a[i][j] && k!=i && k!=j)
	  ok=false;
      if(ok) ans+=a[i][j];
    }
  cout<<ans<<endl;
  return 0 ;
}
