#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll N;
  cin >> N;
  vector<ll> A(N,0),B(N,0),p(N);
  rep(i,N){
    cin >> p.at(i);
    A.at(p.at(i)-1)=i;
    B.at(p.at(i)-1)=i;
  }
  rep(i,N){
    if(i==0){
      A.at(i)=1+A.at(i);
      B.at(N-1-i)=1+B.at(N-1-i);
    }else{
      A.at(i)=A.at(i-1)+1+A.at(i);
      B.at(N-1-i)=B.at(N-i)+1+B.at(N-1-i);
    }
  }
  rep(i,N){
    cout << A.at(i) << " ";
  }
  cout << endl;
  rep(i,N){
    cout << B.at(i) << " ";
  }
  cout << endl;
}
      