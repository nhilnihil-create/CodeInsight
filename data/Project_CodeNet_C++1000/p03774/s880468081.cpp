#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  int a[N], b[N];
  int c[M], d[M];
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> c[i] >> d[i];
  }

  for (int i = 0; i < N; i++) {
    int minD = INT_MAX;
    int minPoint = 0;
    for (int j = 0; j < M; j++) {
      int tmp = abs(a[i] - c[j]) + abs(b[i] - d[j]);
      if (tmp < minD) {
        minPoint = j + 1;
        minD = tmp;
      }
    }

    cout << minPoint << endl;;
  }
}