#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
#define reps1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
using P = pair<int, int>;
using Pl = pair<ll, ll>;
using M = map<int, int>;
using Ml = map<ll, ll>;
ll const INF = 1ll<<61;
double pi = 3.141592653589793238;
ll primenum[1001];
ll MOD = 1e9 + 7;

void sieve(ll n) {
  while(n != 1) {
    bool divflag = false;
    ll i = 2;
    // cout << "a " << n << " " << i << endl;
    while(!divflag){
      if (n % i == 0) {
        n /= i;
        primenum[i]++;
        divflag = true;;
      }
      i++;
      // cout << "b " << n << " " << i << endl;
    }
  }
}

int main() {
  ll n;
  cin >> n;
  reps1(i, n+1) {
    sieve(i);
  }

  ll ans = 1;
  reps1(i, n+1)
    if (primenum[i]) ans = (ans * (primenum[i]+1)) % MOD;

  cout << ans << endl;

  return 0;
}
