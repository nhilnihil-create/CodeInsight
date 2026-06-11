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
  string s, t;
  cin >> s >> t;
  string ans;
  if(s.size() > t.size())
    ans = "GREATER";
  else if(s.size() < t.size())
    ans = "LESS";
  else {
    if(s > t)
      ans = "GREATER";
    else if(s < t)
      ans = "LESS";
    else
      ans = "EQUAL";
  }
  cout << ans << endl;
}