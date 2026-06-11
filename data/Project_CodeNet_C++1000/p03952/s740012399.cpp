#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int n, x;
  cin >> n >> x;
  if (x == 1 || x == 2 * n - 1) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  if (n == 2) {
    REP1(i, 3) cout << i << endl;
    return 0;
  }
  queue<int> que;
  if (x == 2) {
    REP1(i, 2 * n - 1) {
      if (x - 1 <= i && i <= x + 2) continue;
      que.push(i);
    }
    REP(i, n - 2) {
      cout << que.front() << endl;
      que.pop();
    }
    cout << x + 1 << endl;
    cout << x << endl;
    cout << x - 1 << endl;
    cout << x + 2 << endl;
    while (que.size()) {
      cout << que.front() << endl;
      que.pop();
    }
  } else {
    REP1(i, 2 * n - 1) {
      if (x - 2 <= i && i <= x + 1) continue;
      que.push(i);
    }
    REP(i, n - 2) {
      cout << que.front() << endl;
      que.pop();
    }
    cout << x - 1 << endl;
    cout << x << endl;
    cout << x + 1 << endl;
    cout << x - 2 << endl;
    while (que.size()) {
      cout << que.front() << endl;
      que.pop();
    }
  }
  return 0;
}