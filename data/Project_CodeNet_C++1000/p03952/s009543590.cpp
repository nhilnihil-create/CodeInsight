#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, x;
  cin >> N >> x;
  if (x == 1 || x == 2 * N - 1) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  if (N == 2) {
    cout << "1 2 3" << endl;
    return 0;
  }
  vector<int> answer(2 * N - 1);
  iota(answer.begin(), answer.end(), 1);
  if (x <= N) {
    rotate(answer.rbegin(), answer.rbegin() + (N - x), answer.rend());
  } else {
    rotate(answer.begin(), answer.begin() + (x - N), answer.end());
  }
  rep(i, 2 * N - 1) cout << answer[i] << endl;
  return 0;
}
