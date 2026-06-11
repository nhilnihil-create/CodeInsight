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

typedef vector<int> vi;
typedef greater<int> gi;

int main() {
  int N;
  cin >> N;
  vector<int> a(3 * N);
  REP(i, 3 * N) cin >> a[i];
  priority_queue<int, vi, gi> que1;
  vector<ll> l(3 * N);
  ll sum = 0;
  REP(i, 3 * N) {
    sum += a[i];
    que1.push(a[i]);
    while (N < que1.size()) {
      sum -= que1.top();
      que1.pop();
    }
    l[i] = sum;
  }
  priority_queue<int, vi> que2;
  vector<ll> r(3 * N);
  sum = 0;
  RREP(i, 3 * N) {
    sum += a[i];
    que2.push(a[i]);
    while (N < que2.size()) {
      sum -= que2.top();
      que2.pop();
    }
    r[i] = sum;
  }
  ll ans = -1 * 1e15;
  for (int k = N - 1; k < 2 * N; ++k) ans = max(ans, l[k] - r[k + 1]);
  cout << ans << endl;
  return 0;
}