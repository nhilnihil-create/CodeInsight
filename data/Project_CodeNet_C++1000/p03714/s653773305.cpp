#include <bits/stdc++.h>

using namespace std;

template <class T> inline bool chmax(T &a, T b) { /* {{{ */
  if (a < b) {
    a = b;
    return true;
  }
  return false;
} /* }}} */

int main() {
  int N;
  cin >> N;
  vector<int> A(N * 3);
  for (int i = 0; i < N * 3; i++) {
    cin >> A[i];
  }
  vector<vector<long long>> score(N + 1, vector<long long>(2));

  multiset<int> s;
  long long ssum = 0;
  for (int i = 0; i < N; i++) {
    s.insert(A[i]);
    ssum += A[i];
  }
  score[0][0] = ssum;
  for (int i = N; i < N * 2; i++) {
    s.insert(A[i]);
    ssum += A[i];
    auto first = s.begin();
    ssum -= *first;
    s.erase(first);
    score[i - N + 1][0] = ssum;
  }

  s.clear();
  ssum = 0;
  for (int i = N * 2; i < N * 3; i++) {
    s.insert(A[i]);
    ssum += A[i];
  }
  score[N][1] = ssum;
  for (int i = N * 2 - 1; i >= N; i--) {
    s.insert(A[i]);
    ssum += A[i];
    auto last = s.end();
    last--;
    ssum -= *last;
    s.erase(last);
    score[i - N][1] = ssum;
  }

  long long ans = -1e18 - 10;
  for (int i = 0; i < N + 1; i++) {
    chmax(ans, score[i][0] - score[i][1]);
  }
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
