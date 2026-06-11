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

int main() {
  ll x, y;
  cin >> x >> y;
  ll ans;
  if(y > 0) {
    if(x <= -y)
      ans = -y - x + 1;
    else if(x < 0)
      ans = y + x + 1;
    else if(x <= y)
      ans = y - x;
    else
      ans = -y + x + 2;
  } else if(y == 0) {
    if(x < 0)
      ans = -x;
    else
      ans = x + 1;
  } else {
    if(x <= y)
      ans = y - x;
    else if(x < 0)
      ans = -y + x + 2;
    else if(x <= -y)
      ans = -y - x + 1;
    else
      ans = y + x + 1;
  }
  cout << ans << endl;
}