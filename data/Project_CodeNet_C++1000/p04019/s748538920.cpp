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
  map<char, bool> m;
  for (int i = 0; i < s.size(); i++) {
    m[s[i]] = true;
  }
  if ((m['N'] && !m['S']) || (m['S'] && !m['N']) || (m['E'] && !m['W']) ||
      (m['W'] && !m['E'])) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}