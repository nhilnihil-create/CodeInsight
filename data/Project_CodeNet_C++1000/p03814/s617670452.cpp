#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  string s;
  cin >> s;
  ll a_pos = INF, z_pos = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'A')
      a_pos = min(a_pos, (ll)i);
    else if (s[i] == 'Z')
      z_pos = max(z_pos, (ll)i);
  }
  ll ans = z_pos - a_pos + 1;
  cout << ans << endl;
  return 0;
}