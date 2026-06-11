#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  int N, M, K;
  cin >> N >> M >> K;

  if (K == 0) {
    cout << "Yes" << endl;
    return 0;
  } else if (K % N == 0 && K / N <= M) {
    cout << "Yes" << endl;
    return 0;
  } else if (K % M == 0 && K / M <= N) {
    cout << "Yes" << endl;
    return 0;
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      int tmp = N * M - i * j - (N - i) * (M - j);
      if (tmp == K) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;

  return 0;
}