#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const long long LINF = 1000000000000000018ll;
const int INF = 1000000009;
const int mod = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(20) << fixed;

  string s; cin >> s;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    int a = i + 1;
    int b = i + 2;
    if (a < n && s[i] == s[a]) {
      cout << i+1 << " " << a+1 << endl;
      return 0;
    }
    if (b < n && s[i] == s[b]) {
      cout << i+1 << " " << b+1 << endl;
      return 0;
    }
  }
  cout << -1 << " " << -1 << endl;
  return 0;
}