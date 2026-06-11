#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;

int main() {
  ll n;
  cin >> n;
  string s, t;
  cin >> s >> t;

  ll ans, i;
  if (s[0] == t[0]) {
    i = 1;
    ans = 3;
  } else {
    i = 2;
    ans = 6;
  }

  for (; i < s.size(); i++) {
    if (s[i] == t[i]) {
      if (s[i - 1] == t[i - 1])  // ||
        ans = ans * 2 % MOD;
      else  // =|
        ans = ans % MOD;
    } else {
      if (s[i - 1] == t[i - 1])  // |=
        ans = ans * 2 % MOD;
      else  // ==
        ans = ans * 3 % MOD;
      i++;
    }
  }

  cout << ans << endl;
}
