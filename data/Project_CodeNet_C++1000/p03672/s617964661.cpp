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
  ll ans = 0;
  for (int i = 1; i < s.size(); i++) {
    string cand = s.substr(0, s.size() - i);
    if (cand.size() % 2 == 1) continue;
    string b = cand.substr(0, cand.size() / 2);
    string a = cand.substr(cand.size() / 2, cand.size() / 2);
    if (b == a) ans = max(ans, (ll)cand.size());
  }
  cout << ans << endl;
  return 0;
}