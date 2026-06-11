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
  string S;
  cin >> S;
  set<char> s;
  for (int i = 0; i < S.size(); i++) {
    s.insert(S[i]);
  }
  string ans = (s.size() == S.size()) ? "yes" : "no";
  cout << ans << endl;
  return 0;
}