#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int INF = 1001001001;

int main() {
  string s;
  cin >> s;
  int a = -1, ans = 0;
  rep(i, 0, s.size()) {
    if (a == -1 && s[i] == 'A') a = i;
    if (s[i] == 'Z') ans = max(ans, i - a + 1);
  }

  cout << ans << endl;

  return 0;
}
