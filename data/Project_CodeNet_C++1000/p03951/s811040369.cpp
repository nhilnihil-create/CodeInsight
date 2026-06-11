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
  ll N;
  string s, t;
  cin >> N >> s >> t;
  ll double_cnt = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == t[0]) {
      ll cnt = 1;
      while (i + cnt < s.length() && s[i + cnt] == t[cnt]) {
        cnt++;
      }
      double_cnt = max(double_cnt, cnt);
    }
  }
  ll min_len = s.length() + t.length() - double_cnt;
  cout << max(min_len, N) << endl;
  return 0;
}