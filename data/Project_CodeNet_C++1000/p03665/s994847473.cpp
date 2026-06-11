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

  int oddcnt = 0;
  rep(i,n) {
    if (A[i] % 2) oddcnt++;
  }

  if (oddcnt == 0) {
    if (p == 1) {
      cout << 0 << endl;
    } else {
      cout << (1LL<<n) << endl;
    }
  } else {
    cout << (1LL<<n-1) << endl;
  }
  return 0;
}