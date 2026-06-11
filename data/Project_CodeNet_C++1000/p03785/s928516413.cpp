#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
  long long N, C, K;
  cin >> N >> C >> K;

  vector<long long> t(N);
  for (int i = 0; i < N; ++i)
    cin >> t[i];

  sort(t.begin(), t.end());

  long long ret = 1;
  long long next_lim = t[0] + K;
  long long cur_n = 1;
  for (int i = 1; i < N; ++i) {
    if (cur_n == C || t[i] > next_lim) {
      next_lim = t[i] + K;
      cur_n = 1;
      ++ret;
      continue;
    }
    ++cur_n;
  }

  cout << ret << endl;

  return 0;
}