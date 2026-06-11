#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vec = vector<ll>;
using vecp = vector<P>;
using mat = vector<vec>;
using matp = vector<vecp>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define all(v) v.begin(), v.end()



int main(){
  ll N,K;
  cin >> N >> K;
  vec A(1e5,0);
  rep(i,N){
    ll a,b;
    cin >> a >> b;
    A.at(a-1)+=b;
  }
  ll k=0;
  rep(i,1e5){
    k+=A.at(i);
    if(k>=K){
      cout << i+1 << endl;
      return 0;
    }
  }
}
      