#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
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

int main() {
  ll n, m;
  cin >> n >> m;
  vl cum(n + 1, 0);
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    cum[a]++;
    cum[b]--;
  }
  bool ans = true;
  rep(i, n) {
    cum[i + 1] += cum[i];
    if(cum[i + 1] % 2) ans = false;
  }
  cout << (ans ? "YES" : "NO") << endl;
}