#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 55);
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  ll res = INF;
  for (int bit = 0; bit < (1 << n); bit++) {
    if (__builtin_popcount(bit) != k) continue;
    ll tmp = 0;
    int prev = 0;
    for (int i = 0; i < n; i++) {
      if (bit & (1 << i)) {
        if (prev == 0) prev = a[i] - 1;
        tmp += max(prev - a[i] + 1, 0);
        prev = a[i] + max(prev - a[i] + 1, 0);       
      }
      prev = max(prev, a[i]);
    }
    res = min(res, tmp);
  }
  cout << res << endl;
  return 0;
} 