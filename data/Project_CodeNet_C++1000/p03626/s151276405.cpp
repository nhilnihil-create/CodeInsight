// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

/*
[$ s_i \neq t_i]の場合: 
上下で別々のドミノなので前はなにもないか or 1つの縦ドミノ。
なにもない場合は3 x 2 で１つの縦ドミノの場合は2 x 1
次の文字は読み飛ばし。
[$ s_i = t_i]の場合:
上下で１つのドミノなので、前は
i) なにもない 3
ii) １つのドミノ 2
ii) ２つの横ドミノ 1
*/
const ll MOD = 1000000007;
int main() {
  int n; cin >> n;
  string s, t; cin >> s >> t;
  n = s.size();
  ll ans = 1;
  int prev = -1; // -1: 何もなし, 1: １つのドミノ, 2: ２のドミノ
  loop(i,0,n) {
    if (s[i] != t[i]) {
      // --
      // --
      if (prev == -1) ans *= 3 * 2;
      // |--
      // |--
      else if (prev == 1) ans *= 2;
      // -- --
      // -- --
      else ans *= 3;
      ans %= MOD;
      prev = 2;
      i++;
      continue;
    }
    
    // |
    // |
    if (prev == -1) ans *= 3;
    // | |
    // | |
    else if (prev == 1) ans *= 2;
    // --|
    // --|
    else ans *= 1;
    ans %= MOD;
    prev = 1;
  }
  cout << ans << endl;
  return 0;
}
