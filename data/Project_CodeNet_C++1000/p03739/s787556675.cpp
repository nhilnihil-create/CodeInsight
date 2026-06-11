#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
  }

  // 0スタートで
  // 偶数番目が正
  ll ans1 = 0;
  ll sum = 0;
  rep(i, n) {
    sum += a[i];
    if (i % 2 == 0) {
      if (sum <= 0) {
        ans1 += 1 - sum;
        sum = 1;
      }
    } else {
      if (sum >= 0) {
        ans1 += 1 + sum;
        sum = -1; 
      }
    }
  }

  // 奇数番目が正
  ll ans2 = 0;
  sum = 0;
  rep(i, n) {
    sum += a[i];
    if (i % 2 != 0) {
      if (sum <= 0) {
        ans2 += 1 - sum;
        sum = 1;
      }
    } else {
      if (sum >= 0) {
        ans2 += 1 + sum;
        sum = -1; 
      }
    }
  }

  cout << min(ans1, ans2) << endl;
  
  return 0;
}