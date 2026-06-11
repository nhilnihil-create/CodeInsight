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
  vector<int> a(n+1, 0);

  REP(i, 2, n){
    int num = i;
    REP(j, 2, n){
      while(num % j == 0){
        a[j]++;
        num /= j;
      }
    }
  }

  ll ans = 1;
  REP(i, 2, n){
    ans *= a[i] + 1;
    ans %= MOD;
  }

  cout << ans << endl;

  return 0;
}
