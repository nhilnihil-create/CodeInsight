#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
#define all(v) v.begin(), v.end()

int main(){
  ll K,T,m=0;
  cin >> K >> T;
  vector<ll> A(T);
  rep(i,T){
    cin >> A.at(i);
    m=max(m,A.at(i));
  }
  if(m<=(K+1)/2){
    cout << 0 << endl;
    return 0;
  }
  cout << (m-(K+1)/2)*2-1 << endl;
}
      