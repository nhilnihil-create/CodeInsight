#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()


int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  
  //偶数番目が正
  ll sum1 = 0, ans1 = 0;
  for (int i = 0; i < n; i++) {
    sum1 += a[i];
    if (i % 2 == 0 && sum1 <= 0) {
      ans1 += 1 - sum1;
      sum1 = 1;
    }
    if (i % 2 == 1 && sum1 >= 0) {
      ans1 += 1 + sum1;
      sum1 = -1;
    }
  }
  
  //偶数番目が負
  ll sum2 = 0, ans2 = 0;
  for (int i = 0; i < n; i++) {
    sum2 += a[i];
    if (i % 2 == 1 && sum2 <= 0) {
      ans2 += 1 - sum2;
      sum2 = 1;
    }
    if (i % 2 == 0 && sum2 >= 0) {
      ans2 += 1 + sum2;
      sum2 = -1;
    }
  }
  cout << min(ans1, ans2) << endl;
}