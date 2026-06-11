#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int N, C, K;
  cin >> N >> C >> K;
  vector<int> T(N);
  for (int i = 0; i < N; ++i) cin >> T[i];
  sort(T.begin(), T.end());

  int answer = 0;
  int idx = 0;
  while (idx < N) {
    int deadline = T[idx++] + K;
    int people = 1;
    answer++;
    while (idx < N && T[idx] <= deadline && people < C) {
      idx++;
      people++;
    }
  }
  cout << answer << endl;
  return 0;
}