#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N, C, K;
vector<int> T;

bool isOK(int m) {
  int idx = 0;
  while (idx < N) {
    int deadline = T[idx] + K;
    int people = 1;
    while (idx < N && T[idx] <= deadline && people <= C) {
      idx++;
      people++;
    }
    if (m-- == 0) return false;
  }
  return true;
}

int main(void) {
  cin >> N >> C >> K;
  T.resize(N);
  for (int i = 0; i < N; ++i) cin >> T[i];
  sort(T.begin(), T.end());

  int left = N / C;
  int right = N;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (isOK(mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  cout << left << endl;
  return 0;
}