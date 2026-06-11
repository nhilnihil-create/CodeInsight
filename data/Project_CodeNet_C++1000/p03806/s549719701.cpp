#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long int li;
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
const int INF = 1000000;
const double PI=3.14159265359;



int main(){

  ll n;cin>>n;
  ll ma,mb;cin>>ma>>mb;
  ll a[n],b[n],c[n];rep(i,0,n)cin>>a[i]>>b[i]>>c[i];
  ll dp[410][410];
  rep(i,0,410)rep(j,0,410)dp[i][j]=INF;
  dp[0][0]=0;
  rep(i,0,n){
    repr(j,400,a[i]){
      repr(k,400,b[i]){
        chmin(dp[j][k],dp[j-a[i]][k-b[i]]+c[i]);
      }
    }
  }
  ll ans=INF;
  rep(i,1,n+1)chmin(ans,dp[ma*i][mb*i]);

  if(ans==INF)out(-1);
  else out(ans);


  return 0;
}
