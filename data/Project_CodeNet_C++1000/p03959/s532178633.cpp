#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N; cin >> N;
  ll T[N]; rep(i,N) cin >> T[i];
  ll A[N]; rep(i,N) cin >> A[i];
  int pt; pt = lower_bound(T,T+N,T[N-1]) - T;
  int pa; pa = upper_bound(A,A+N,A[0],greater<ll>()) - (A+1);

  if (pt>pa||T[N-1]!=A[0]) { cout << 0 << endl; return 0; }
  ll result = 1;
  rep(i,max(0,pa-pt-1)) { result *= A[0]; result %= MOD; }
  for (int i=1; i<=pt; i++) {
    if (T[i]==T[i-1]) { 
      result *= T[i];
      result %= MOD;
    }
  }
  for (int i=N-1; i>=pa; i--) {
    if (A[i]==A[i+1]) { 
      result *= A[i];
      result %= MOD;
    }
  }  
  // cout << pt << " " << pa << endl;
  cout << result << endl;
  return 0;
}