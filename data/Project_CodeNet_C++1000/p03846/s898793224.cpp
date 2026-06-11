#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;
const int MOD = 1000000007;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(all(a));

  rep(i, n){
    if((n+i) % 2 == 0 && a[i] != i+1){
      cout << 0 << endl;
      return 0;
    }
    else if((n+i) % 2 == 1 && a[i] != i){
      cout << 0 << endl;
      return 0;
    }
  }

  ll ans = 1;
  rep(i, n/2){
    ans *= 2;
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}
