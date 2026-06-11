#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

signed main() {
  string s;
  cin >> s;
  ll N = s.size();

  ll ans = N*(N-1)/2 + 1; // nC2: 全組合せ

  // 両端が同じ文字の部分文字列 dabcd と、両端を取り除いた部分文字列 abc は重複しているので除く
  vector<ll> hist(26, 0);
  for (char c: s) {
    hist[c-'a']++;
  }
  for (ll x : hist) {
    if (x>=2)
      ans -= x*(x-1)/2;
  }
  cout<<ans<<endl;
}
