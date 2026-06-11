#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
map<long long, int> zip;
vector<long long> unzip;
template <typename T> void compress(vector<T>& v) {
  for (int i = 0; i < (int) v.size(); i++) unzip.push_back(v[i]);
  sort(unzip.begin(), unzip.end());
  unzip.erase(unique(unzip.begin(), unzip.end()), unzip.end());
  for (int i = 0; i < (int) unzip.size(); i++) zip[unzip[i]] = i + 1;
}
template<typename T>
class Fenwick {
private:
  int n;
  vector<T> bit;
public:
  Fenwick() : n(-1) {}
  Fenwick(int n_, T d = T()) : n(n_), bit(n + 1, d) {}

  inline void add(int i, T val) {
    if (i == 0) return;
    for (int x = i; x <= n; x += (x & -x)) bit[x] += val;
  }

  // [1, i);
  inline T get(int i) {
    T res = T();
    for (int x = i; x > 0; x -= (x & - x)) res += bit[x];
    return res;
  }

  // return [i, j);
  inline T get(int i, int j) {
    return get(j - 1) - get(i - 1);
  }

  inline int lower_bound(int val) {
    if (val <= 0) return 0;
    int x = 0, r = 1;
    while (r < n) r <<= 1;
    for (int k = r; k > 0; k >>= 1) {
      if (x + k <= n && bit[x + k] < val) {
        val -= bit[x + k];
        val += k;
      }
    }
    return x + 1;
  }

  const T& operator[](const int &i) const {
    return bit[i];
  }
};
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector <long long> sum(n + 1);
  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + a[i] - k;
  }
  compress(sum);
  Fenwick<int> bit(n + 100);
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    ans += bit.get(zip[sum[i]]);
    bit.add(zip[sum[i]], 1);
  }
  cout << ans << '\n';
  return 0;
}