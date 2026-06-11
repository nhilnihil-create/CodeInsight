#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using T = tuple<ll,ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll H,W,N;
  cin >> W >> H >> N;
  vector<vector<ll>> A(W,vector<ll>(H,0));
  rep(k,N){
    ll x,y,a;
    cin >> x >> y >> a;
    if(a==1){
      rep(i,x){
        rep(j,H){
          A.at(i).at(j)=1;
        }
      }
    }
    if(a==2){
      for(ll i=x;i<W;i++){
        rep(j,H){
          A.at(i).at(j)=1;
        }
      }
    }
    if(a==3){
      rep(i,W){
        rep(j,y){
          A.at(i).at(j)=1;
        }
      }
    }
    if(a==4){
      rep(i,W){
        for(ll j=y;j<H;j++){
          A.at(i).at(j)=1;
        }
      }
    }
  }
  ll ans=0;
  rep(i,W)rep(j,H){
    if(A.at(i).at(j)==0) ans++;
  }
  cout << ans << endl;
}