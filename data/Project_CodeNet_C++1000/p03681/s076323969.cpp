#include <bits/stdc++.h>
#define rep(i,a,n) for(int i =a; i<n; i++) 
#define ll long long
#define MOD 1000000007
using namespace std;

ll kaijou(ll a) {
  ll ans =1;
  rep(i,1,a+1) {
    ans *= i; ans %= MOD;
  }
  return ans;
}

int main() {
  ll N,M; cin >> N >> M;
  if (abs(N-M) >=2) {
    cout << 0 << endl; return 0;
  }
  ll ans;
  if (M != N) {
    ans = kaijou(M) * kaijou(N);
  } else {
    ans = 2 * kaijou(M) * kaijou(N);
  }
  ans %= MOD;
  cout << ans << endl;
}