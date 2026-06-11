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
  vector<vi> ms(m);
  rep(i, n) {
    int x;
    cin >> x;
    ms[x % m].push_back(x);
  }
  rep(i, m) sort(all(ms[i]));
  int ans = 0;
  rep(i, m / 2 + 1) {
    if(i == 0 || i == m - i) {
      ans += ms[i].size() / 2;
    } else {
      vi s = ms[i];
      vi t = ms[m - i];
      if(s.size() < t.size()) swap(s, t);
      int now = 0;
      rep(j, s.size() - 1) {
        if(s.size() - now * 2 < t.size() + 2) break;
        if(s[j] == s[j + 1]) {
          now++;
          j++;
        }
      }
      ans += now + t.size();
    }
  }
  cout << ans << endl;
}