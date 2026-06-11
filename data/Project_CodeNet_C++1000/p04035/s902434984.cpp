#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()


int main(){
  ll N,L,t=-1;
  cin >> N >> L;
  vector<ll> A(N);
  rep(i,N) cin >> A.at(i);
  rep(i,N-1){
    if(A.at(i)+A.at(i+1)>=L){
      t=i;
      cout << "Possible" << endl;
      break;
    }
  }
  if(t==-1){
    cout << "Impossible" << endl;
    return 0;
  }
  rep(i,t){
    cout << i+1 << endl;
  }
  for(ll i=N-2;i>t;i--){
    cout << i+1 << endl;
  }
  cout << t+1 << endl;
  
}