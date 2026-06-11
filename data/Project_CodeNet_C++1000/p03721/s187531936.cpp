#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  vector<ll> cnt(100001, 0);
  rep(i, n) cnt[a[i]] += b[i];
  ll c = 0;
  rep(i, 100001) {
    c += cnt[i];
    if (c >= k) {
      cout << i << endl;
      break;
    }
  } 
  return 0;
}