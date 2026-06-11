#include <iostream>
#include <new>
using namespace std;

int main() {
  int N, M;
  cin >> N;
  int *T, *P, *X;
  T = new (nothrow) int[N];
  for (int i = 0; i < N; i++) {
    cin >> T[i];
  }

  cin >> M;
  P = new (nothrow) int[M];
  X = new (nothrow) int[M];
  for (int i = 0; i < M; i++) {
    cin >> P[i] >> X[i];
  }

  for (int i = 0; i < M; i++) {
    int total_time = 0;
    int originalT = T[P[i]-1];
    // printf("P[%d]=%d\n", i, P[i]);
    T[P[i]-1] = X[i];
    // printf("T[%d]=%d\n", i, T[i]);
    for (int j = 0; j < N; j++) {
      total_time += T[j];
    }
    T[P[i]-1] = originalT;
    cout << total_time;
    if (i != M-1) {
      cout << endl;
    }
  }

  return 0;
}