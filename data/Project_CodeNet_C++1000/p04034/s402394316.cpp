#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 1000000000000000;
#define all(v) v.begin(), v.end()


int main(){
  ll N,M;
  cin >> N >> M;
  vector<ll> A(N,1),B(N,0);
  B.at(0)=1;
  rep(i,M){
    ll x,y;
    cin >> x >> y;
    x--;
    y--;
    if(B.at(x)==1){
      if(A.at(x)==1){
        B.at(x)=0;
        A.at(x)=0;
        A.at(y)++;
        B.at(y)=1;
      }else{
        A.at(x)--;
        A.at(y)++;
        B.at(y)=1;
      }
    }else{
      A.at(x)--;
      A.at(y)++;
    }
  }
  ll ans=0;
  rep(i,N){
    if(B.at(i)==1){
      ans++;
    }
  }
  cout << ans << endl;
}