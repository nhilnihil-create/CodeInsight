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
ll a[N],x[N],y[N];
void update1(int l,int r,ll val)//[l,r)
{
  x[l]+=val; x[r]-=val;
}
void update2(int l,int r)//[l,r)
{
  y[l]--; y[r]++;
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(NULL) ; cout.tie(NULL) ;
  int n,m;
  cin>>n>>m;
  rep(i,1,n+1) cin>>a[i];
  rep(i,1,n)
    {
      if(a[i]<a[i+1])
	{
	  //for x<=a[i] && x>a[i+1]
	  update1(1,a[i]+1,a[i+1]-a[i]);
	  update1(a[i+1]+1,m+1,a[i+1]-a[i]);
	  //for x lies ( a[i],a[i+1] ]
	  update1(a[i]+1,a[i+1]+1,1+a[i+1]);
	  update2(a[i]+1,a[i+1]+1);
	}
      else
	{
	  //for x<=a[i+1]
	  update1(1,a[i+1]+1,1+a[i+1]);
	  update2(1,a[i+1]+1);
	  //for x>a[i+1] && x<=a[i]
	  update1(a[i+1]+1,a[i]+1,a[i+1]-a[i]+m);
	  //for x>a[i]
	  update1(a[i]+1,m+1,1+a[i+1]+m);
	  update2(a[i]+1,m+1);
	}
    }
  rep(i,1,m+1) x[i]+=x[i-1],y[i]+=y[i-1];
  ll ans=LLONG_MAX;
  rep(i,1,m+1) ans=min(ans,x[i]+y[i]*i);
  cout<<ans<<endl;
  return 0 ;
}
