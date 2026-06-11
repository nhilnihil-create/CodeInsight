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
  int n, m;
  cin >> n >> m;
  vi l(n, 0);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    l[a - 1]++;
    l[b - 1]++;
  }
  bool ok = true;
  rep(i, n) if(l[i] % 2) ok = false;
  cout << (ok ? "YES" : "NO") << endl;
}