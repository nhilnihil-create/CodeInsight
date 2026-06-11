#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;  // vi <=> vl
using P = pair<int, int>;  // int <=> ll
const int MOD = 1e9+7;
const double EPS = 1e-9;

int main() {
  int N; cin >> N;
  string S, T;
  cin >> S >> T;
  
  int pos;
  ll ans;
  bool vertical;

  if (S[0] == T[0]) {
    pos = 1;
    ans = 3;
    vertical = true;
  } else {
    pos = 2;
    ans = 6;
    vertical = false;
  }

  while (pos < N) {
    if (S[pos] == T[pos]) {
      if (vertical) (ans *= 2) %= MOD;
      else (ans *= 1) %= MOD;
      vertical = true;
      pos += 1;
    }
    else {
      if (vertical) (ans *= 2) %= MOD;
      else (ans *= 3) %= MOD;
      vertical = false;
      pos += 2;
    }
  }

  cout << ans << endl;
  return 0;
}
