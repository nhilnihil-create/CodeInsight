#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main() {
  int N, C, K;
  cin >> N >> C >> K;

  vector<int> t(N);
  rep(i, N) { cin >> t[i]; }
  sort(t.begin(), t.end());

  queue<int> q;
  int result = 0;
  rep(i, N) {
    while (!q.empty() && q.front() < t[i]) {
      int c = C;
      while (c > 0 && !q.empty()) {
        c--;
        q.pop();
      }
      result++;
    }
    q.push(t[i] + K);
  }
  result += (q.size() + C - 1) / C;
  cout << result << endl;
  return 0;
}