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
  int n;
  cin >> n;
  vi a(n), b(n);
  rep(i, n) {
    int p;
    cin >> p;
    p--;
    a[p] = 2e4 * (p + 1);
    b[p] = 8e8 + i - a[p];
  }
  rep(i, n) cout << a[i] << (i == n - 1 ? '\n' : ' ');
  rep(i, n) cout << b[i] << (i == n - 1 ? '\n' : ' ');
}