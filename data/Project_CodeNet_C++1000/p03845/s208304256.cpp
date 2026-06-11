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
  int N, M;
  cin >> N;
  vector<int> T(N);
  rep(i, 0, N) cin >> T[i];

  cin >> M;
  rep(i, 0, M) {
    int p, x;
    cin >> p >> x;
    p--;

    int ans = 0;
    rep(i, 0, N) {
      if (i == p)
        ans += x;
      else
        ans += T[i];
    }
    cout << ans << endl;
  }

  return 0;
}
