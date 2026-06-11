#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lb;
#define rep(i,j,n) for (ll i = j; i < (n); i++)
#define repr(i,j,n) for(ll i = j; i >= (n); i--)
#define each(i,mp) for(auto& i:mp)
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

  ll n,m,k;cin>>n>>m>>k;
  bool e=false;
  // for(ll i=0;n-2*i>0;i++){
  rep(i,0,n+1){
    ll a=k-i*m;
    ll b=n-2*i;
    if(a==0)e=true;
    else{
      if(b!=0){
        if(a%b==0&&(0<=a/b&&a/b<=m))e=true;
      }

    }
  }

  if(e)out("Yes");
  else out("No");

  return 0;
}
