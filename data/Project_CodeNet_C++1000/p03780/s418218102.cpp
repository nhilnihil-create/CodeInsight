#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

int N,K;

bool ok(int mid,vector<ll> &a) {
  if(mid==N) return true;
  if(mid==-1) return false;
  vector<vector<bool>> dp(N+1,vector<bool>(K,false));
  dp[0][0] = true;
  rep(i,N) {
    rep(j,K) {
      if(i==mid) {
	dp[i+1][j] = dp[i][j];
	continue;
      }
      if(dp[i][j]) {
	dp[i+1][j] = true;
	if(j+a[i] < K) dp[i+1][j+a[i]] = true;
      }
    }
  }
  for(int i =max(0,(int)(K - a[mid])); i < K; i++) {
    if(dp[N][i]) return true;
  }
  return false;
}

int b_search(vector<ll> &a) {
  int l = -1,r = N,mid;
  while(r-l>1) {
    mid = (l+r)/2;
    // cout<<mid<<endl;
    if(ok(mid,a)) r = mid;
    else l = mid;
  }
  return r;
}

int main(){
  cin>>N>>K;
  vector<ll> a(N);
  rep(i,N) cin>>a[i];
  sort(a.begin(),a.end());
  int ans = b_search(a);
  cout<<ans<<endl;
}
