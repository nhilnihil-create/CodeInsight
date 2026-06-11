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
  string ans = "";
  for (int i = 0; i < s.length(); i++) {
    if ((i + 1) % 2 == 1) ans += s[i];
  }
  cout << ans << endl;
  return 0;
}