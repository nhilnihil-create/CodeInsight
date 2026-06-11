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
  int N, x = 0;
  cin >> N;
  char c;
  int ans = 0;
  rep(i, 0, N) {
    cin >> c;
    if (c == 'I')
      x++;
    else if (c == 'D')
      x--;
    ans = max(ans, x);
  }

  cout << ans << endl;

  return 0;
}
