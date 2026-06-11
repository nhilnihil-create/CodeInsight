#include <bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T>
bool PN(T x){ if (x <= 1) return false; if (x == 2) return true; for (int i = 2; i < sqrt(x) + 1; i++) if (x % i == 0) return false; return true;}
const ll MOD = 1e9+7;
long long Comb(int n, int i){long long ans = 1; if(i == 0 || i == n) return 1; else {for(int j = 1; j <= i; ++j){
      ans *=(n+1-j);
      ans /= j;
      ans %= MOD;} }return ans;}


void solve()
{
  int n, m; cin >> n >> m;
  ll ans = 1;
  if(abs(n-m) >1) {
    cout << 0 << endl;
    return;
  } else {
    int M = max(n, m);
    int mm = min(n, m);
    for(int i = 1; i <= mm; ++i){
      ans *= (ll)i;
      ans %= MOD;
      ans *= (ll)i;
      ans %= MOD;
    }
    if(abs(n-m) == 1){
      ans *= M; ans%=MOD;
    } else {
      ans *= 2;
      ans %= MOD;
    }
  } 
  cout << ans << endl;
}

int main()
{
  solve();
  return 0;
}
