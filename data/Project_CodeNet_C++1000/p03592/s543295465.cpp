#include<iostream>
using namespace std;
int main () {
  int N, M, K;
  cin >> N >> M >> K;
  for (int i = 0; i <= N; i ++) {
    for (int j = 0; j <= M; j ++) {
      int S = N * M;
      int p = i * j;
      int q = (N - i) * (M - j);
      if (S - p - q == K) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}