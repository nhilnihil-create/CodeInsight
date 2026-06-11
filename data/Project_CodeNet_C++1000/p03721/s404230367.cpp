#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define MOD 1000000007
typedef long long ll;

using namespace std;

const int AMAX = 100000;
ll cnt[AMAX + 1];

int main() {
  int n;
  ll k;
  cin >> n >> k;

  REP(i, n) {
    int A, B;
    cin >> A >> B;
    cnt[A] += B;
  }

  FOR(i, 1, AMAX+1){
    if (k <= cnt[i]) {
      cout << i << endl;
      break;
    }
    k -= cnt[i];
  }

  return (0);
}