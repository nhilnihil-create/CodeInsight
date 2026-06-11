#include <bits/stdc++.h>
using namespace std;

#define INF (1LL << 31 - 1)
#define MOD int(1e9+7)
#define repi(i,j,n) for(int i = (j); i < (n); ++i)
#define rep(i,n) repi(i,0,n)
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()

inline void init() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

using ll = long long;

ll n;

int main() {
  init();
  cin >> n;
  ll sum = 0, p;

  for (int i = 1; sum < n; ++i) {
    p = i;
    sum += i;
  }

  int k = sum - n;
  //cout << "sum = " << sum << endl;

  if (sum == n) {
    for (int i = 1; i <= p; ++i) {
      cout << i << endl;
    }
  }
  else {
    for (int i = 1; i <= p; ++i) {
      if (i != k) cout << i << endl;
    }
  }

  return 0;
}