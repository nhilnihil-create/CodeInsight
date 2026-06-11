#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i,s,n) for(ll i = (s); i < (n); i++)
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define repR(i,s,n) for(ll i = (n-1); i >= (s); i--)
#define repR0(i,n) repR(i,0,n)
#define repR1(i,n) repR(i,1,n+1)

#define BR "\n"
#define SP " "
#define SHOW(x) for(int i = 0; i < x.size(); i++) { cout << x[i] << SP; } cout << BR;
#define SHOW2(x) for(int j = 0; j < x.size(); j++) { SHOW(x[j]); } cout << BR;
#define fcout cout << fixed << setprecision(18)

int main() {
  int N; cin >> N;
  string S1, S2; cin >> S1 >> S2;
  ll MOD = 1e9 + 7;

  ll ans = 1;
  rep0(i, N) {
    if (i == 0) {
      ans = ((S1[0] == S2[0])? 3: 6);
    } else if (S1[i - 1] == S1[i]) {
      ans *= 1;
    } else if (S1[i - 1] == S2[i - 1] && S1[i] == S2[i]) {
      ans *= 2;
    } else if (S1[i - 1] != S2[i - 1] && S1[i] == S2[i]) {
      ans *= 1;
    } else if (S1[i - 1] == S2[i - 1] && S1[i] != S2[i]) {
      ans *= 2;
    } else if (S1[i - 1] != S2[i - 1] && S1[i] != S2[i]) {
      ans *= 3;
    }
    ans %= MOD;
  }

  cout << ans << BR;
  return 0;
}