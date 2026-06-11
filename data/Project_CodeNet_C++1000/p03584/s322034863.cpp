#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

#define INF 1e9

int main(){
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N), B(N);
  REP(i, N){
    cin >> A[i] >> B[i];
  }
  ll ans = 0;
  REP(i, N){
    bool flag = true;
    REP(j, 30){
      if((K>>j & 1)==0&&(A[i]>>j & 1)){
        flag = false;
        break;
      }
    }
    if(flag){
      ans+= B[i];
    }
  }
  cerr << ans << endl;
  REP(b, 31){
    if((K >> b & 1) ==0) continue;
    ll value = 0;
    REP(i, N){
      if(A[i] >> b & 1) continue;
      bool flag = true;
      FOR(j, b, 31){
        if((K >> j & 1)==0 && (A[i]>>j & 1)){
          flag = false;
          break;
        }
      }
      if(flag){
        value += B[i];
      }
    }
    cerr << "b:" << b << " value:" << value << endl;
    ans = max(ans, value);
  }
  cout << ans << endl;
  return 0;
}
