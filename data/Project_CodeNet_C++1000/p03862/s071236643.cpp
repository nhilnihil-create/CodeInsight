#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n, x;
  cin >> n >> x;
  vl a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  rep(i, n) if(a[i] > x) {
    ans += a[i] - x;
    a[i] = x;
  }
  rep2(i, 1, n - 1) if(a[i - 1] + a[i] > x && a[i] + a[i + 1] > x) {
    ll d = min(a[i - 1] + a[i], a[i] + a[i + 1]) - x;
    ans += d;
    a[i] -= d;
  }
  rep(i, n - 1) if(a[i] + a[i + 1] > x) {
    ll d = a[i] + a[i + 1] - x;
    ans += d;
    a[i] -= d;
  }
  cout << ans << endl;
}