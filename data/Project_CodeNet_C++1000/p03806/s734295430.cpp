#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lb;
#define rep(i,j,n) for (ll i = j; i < (n); i++)
#define repr(i,j,n) for(ll i = j; i >= (n); i--)
#define all(x) (x).begin(),(x).end()
#define CLR(mat,f) memset(mat, f, sizeof(mat))
#define IN(a, b, x) (a<=x&&x<b)
#define out(ans) cout << ans << endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef pair<ll,ll>P;
const ll mod=1e9+7;
const ll INF = 1LL<<60;
const ll m=1LL<<32;

int main(){

  ll n;cin>>n;
  ll ma,mb;cin>>ma>>mb;
  ll a[n],b[n],c[n];rep(i,0,n)cin>>a[i]>>b[i]>>c[i];
  ll max_a=accumulate(a,a+n,0)+1;
  ll max_b=accumulate(b,b+n,0)+1;

  ll dp[max_a][max_b];//aグラム][bグラム]
  rep(i,0,max_a)rep(j,0,max_b)dp[i][j]=INF;
  dp[0][0]=0;
  ll ans=INF;
  rep(k,0,n){
    repr(i,max_a-1,a[k]){
      repr(j,max_b-1,b[k]){
          chmin(dp[i][j],dp[i-a[k]][j-b[k]]+c[k]);
        if(i*mb==j*ma){
          chmin(ans,dp[i][j]);
        }
      }
    }

  }
  if(ans==INF)out(-1);
  else out(ans);

  return 0;
}
