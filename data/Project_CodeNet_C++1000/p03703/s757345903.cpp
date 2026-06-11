#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

template <typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n = 0) : n(n), d(n + 1) {}
  void add(int i, T x = 1) {
    for(i++; i <= n; i += i & -i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for(i++; i; i -= i & -i) {
      x += d[i];
    }
    return x;
  }
};

int main() {
  ll n, k;
  cin >> n >> k;
  vl s(n + 1, 0);
  rep(i, n) {
    ll a;
    cin >> a;
    a -= k;
    s[i + 1] = s[i] + a;
  }
  vl ss = s;
  sort(all(ss));
  ss.erase(unique(all(ss)), ss.end());
  BIT<ll> b(n + 1);
  ll ans = 0;
  rep(i, n + 1) {
    ll in = lower_bound(all(ss), s[i]) - ss.begin();
    ans += b.sum(in);
    b.add(in);
  }
  cout << ans << endl;
}