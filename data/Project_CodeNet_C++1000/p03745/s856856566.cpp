/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

vector<vector<bool>> A;
vector<vector<bool>> T;

bool Matches(const int64_t r, const int64_t c) {
  const int64_t M = static_cast<int64_t>(T.size());
  for (int64_t i = 0; i < M; ++i) {
    for (int64_t j = 0; j < M; ++j) {
      if (A[r + i][c + j] != T[i][j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N;
  cin >> N;
  vector<int64_t> A(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> A[i];
  }

  if (N <= 2) {
    cout << 1 << endl;
    return 0;
  }
  int64_t result = 1;
  int64_t start = 0;
  while (start < N) {
    int64_t compare = start + 1;
    while (compare < N && A[start] == A[compare]) {
      ++compare;
    }
    if (compare >= N) {
      break;
    }

    bool increase = (A[start] < A[compare]);

    while (compare < N && compare < N) {
      if (increase && A[compare - 1] > A[compare]) {
        break;
      }
      if (!increase && A[compare - 1] < A[compare]) {
        break;
      }
      ++compare;
    }
    if (compare >= N) {
      break;
    }
    ++result;
    start = compare;
  }
  cout << result << endl;
  return 0;
}
