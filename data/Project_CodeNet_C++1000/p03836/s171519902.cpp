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

void f(ll n, char c) { rep(i, n) cout << c; }

int main() {
  ll sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  f(ty - sy, 'U');
  f(tx - sx, 'R');
  f(ty - sy, 'D');
  f(tx - sx + 1, 'L');
  f(ty - sy + 1, 'U');
  f(tx - sx + 1, 'R');
  f(1, 'D');
  f(1, 'R');
  f(ty - sy + 1, 'D');
  f(tx - sx + 1, 'L');
  cout << 'U' << endl;
}