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
  rep(i, 0, s.size()) {
    if ((i + 1) % 2 == 0) continue;
    cout << s[i];
  }
  cout << endl;

  return 0;
}
