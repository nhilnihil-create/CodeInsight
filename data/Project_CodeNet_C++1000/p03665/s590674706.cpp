#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, p; cin >> n >> p;
  vector<int> A(n);
  rep(i,n) cin >> A[i];

  const int N = 55;
  vector<vector<ll>> pas(N, vector<ll>(N,1));
  rep(i,N) {
    rep(j,N) {
      if (0<j && j<=i) {
        pas[i][j] = pas[i-1][j-1] + pas[i-1][j];
      } else {
       if (i<j) pas[i][j] = 0;
      }
    }
  }

  int oddcnt = 0, evencnt = 0;
  rep(i,n) {
    if (A[i] % 2) oddcnt++;
    else evencnt++;
  }

  ll es = 0, os = 0;
  for (int i = 0; i<= evencnt; i++) {
    es += pas[evencnt][i];
  }
  for (int i = p; i <= oddcnt; i+=2) {
    os += pas[oddcnt][i];
  }
  cout << es * os << endl;
  return 0;
}