#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, L;
  cin >> N >> L;
  vector<int> A(N);
  rep(i, N) { cin >> A[i]; }
  rep(i, N) {
    if (i == 0) {
      if ((A[0] + A[1]) < L) continue;
      cout << "Possible" << endl;
      for (int j = N - 1; j > 0; --j) {
        cout << j << endl;
      }
      return 0;
    } else if (i == N - 1) {
      if ((A[N - 1] + A[N - 2]) < L) continue;
      cout << "Possible" << endl;
      for (int j = 1; j < N; ++j) {
        cout << j << endl;
      }
      return 0;
    }

    vector<int> answer;
    if ((A[i] + A[i - 1]) >= L) {
      answer.emplace_back(i);
      for (int j = i - 1; j > 0; --j) answer.emplace_back(j);
      for (int j = i + 1; j < N; ++j) answer.emplace_back(j);
    } else if ((A[i] + A[i + 1]) >= L) {
      answer.emplace_back(i + 1);
      for (int j = i + 2; j < N; ++j) answer.emplace_back(j);
      for (int j = i; j > 0; --j) answer.emplace_back(j);
    } else {
      continue;
    }
    cout << "Possible" << endl;
    for (int j = N - 2; j >= 0; --j) {
      cout << answer[j] << endl;
    }
    return 0;
  }
  cout << "Impossible" << endl;
  return 0;
}
