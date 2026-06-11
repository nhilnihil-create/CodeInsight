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
const ll INF = 1LL<<60;

int main(){

  ll n,k;cin>>n>>k;
  ll a[n];rep(i,0,n)cin>>a[i];


  ll ans=INF;
  rep(bit,0,(1<<n)){
    ll count=0,cost=0;
    ll ma=0;
    rep(i,0,n){
      ll height=a[i];
      if((bit>>i)&1){
        count++;
        if(ma>=a[i]){
          cost+=ma-a[i]+1;
          height=ma+1;
        }
      }
      chmax(ma,height);
    }
    if(count>=k)chmin(ans,cost);
  }

  out(ans);


  return 0;
}
