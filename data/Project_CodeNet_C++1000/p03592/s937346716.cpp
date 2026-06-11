#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, M, K;
  cin >> N >> M >> K;

  vector<bool> NM(N * M + 1, false);
  for (int i = 0; i < N; ++i) {
    int num = i * M;
    NM[num] = true;
    for (int j = 0; j < M; ++j) {
      num += (N - i);
      num -= i;
      NM[num] = true;
    }
  }

  if (NM[K])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
