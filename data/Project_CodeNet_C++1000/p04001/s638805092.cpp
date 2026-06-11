#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int N = 0;
  N = s.size() - 1;
  ll ans = 0;
  ll num_s = stoll(s);
  
  rep(tmp, 1 << (N)) {
    if (tmp == 0) {
        continue;
    }
    bitset<9> k(tmp);
    int pre = -1;
    vector<ll> num_list;
    rep(i, N) {
      if (k[i] == 1) {
        string num_str = s.substr(N - i, i - pre);
        pre = i;
        num_list.push_back(stoll(num_str));
      }
    }
    num_list.push_back(stoll(s.substr(0, N - pre)));
    ans += accumulate(num_list.begin(), num_list.end(), 0);
  }
  printf("%lld\n", ans + num_s);
  return 0;
}
