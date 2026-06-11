#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll N,M;
  cin >> N >> M;
  vector<P> A(N),C(M);
  rep(i,N){
    cin >>A.at(i).first >> A.at(i).second;
  }
  rep(i,M){
    cin >>C.at(i).first >> C.at(i).second;
  }
  rep(i,N){
    ll a=INF,b;
    rep(j,M){
      if(abs(A.at(i).first-C.at(j).first)+abs(A.at(i).second-C.at(j).second)<a){
        b=j+1;
        a=abs(A.at(i).first-C.at(j).first)+abs(A.at(i).second-C.at(j).second);
      }
    }
    cout << b << endl;
  }
  
}