#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 10e17
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define mod 1000000007
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { cerr << (itr) << " "; }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

#define int long long

signed main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  repr(i, n, 0) cin >> a[i];

  int ans = numeric_limits<int>::max();
  for (int i = 0; i < (1 << n); ++i) {
    vector<bool> bits(n);
    for (int j = 0; j < n; ++j) {
      bits[j] = (i >> j) & 1;
    }

    auto cnt = count(bits.begin(), bits.end(), 1);
    if (cnt < k) continue;

    int pre_max = 0;
    int temp = 0;
    for (int j = 0; j < n; ++j) {
      // 見えるようにする。
      if (bits[j] && a[j] - pre_max <= 0) {
        temp += pre_max - a[j] + 1;
        pre_max = pre_max + 1;
      } else if (bits[j] && a[j] - pre_max > 0) {
        pre_max = a[j];
      } else if (!bits[j] && a[j] - pre_max > 0) {
        pre_max = a[j];
      }
    }

    chmin(ans, temp);
  }

  cout << ans << endl;
}