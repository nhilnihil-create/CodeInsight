#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  string s1,s2;
  cin >> s1 >> s2;
  int mod = 1000000007;

  ll ans;
  bool is_befv;
  rep(i, n) {
    bool is_v = s1[i] == s2[i];

    if(i == 0) {
      ans = is_v ? 3 : 6;
      is_befv = is_v;
      if(!is_v) i++;
      continue;
    }

    if(is_befv) {
      if(is_v) {
        ans = (ans * 2) % mod;
      } else {
        ans = (ans * 2) % mod;
      }
    } else {
      if(!is_v) {
        ans = (ans * 3) % mod;
      }
    }

    if(!is_v) i++;
    is_befv = is_v;
  }

  cout << ans << endl;
}
