// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

/*
 * 初期状態のピースでSccを可能な限り作って損をすることはない.
 * cが2未満しか余らなかった場合、終了.
 * cが2以上余っているということはSが枯渇したので、ccccをいくつ作れるかに帰着される.
 */
int main() {
  ll S, c; cin >> S >> c;
  ll ans = 0;
  ll d = min(S, c/2);
  S -= d;
  c -= d*2;
  ans += d;
  if (c < 2) {
    cout << ans << endl;
    return 0;
  }
  
  ans += c/ 4;
  cout << ans << endl;
  return 0;
}
