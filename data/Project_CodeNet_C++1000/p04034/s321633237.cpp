#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, X, Y;
  cin >> N >> M;
  vector V(N, 1), B(N, 0);
  B.at(0) = 1;
  while (cin >> X >> Y) {
    V.at(--X)--, V.at(--Y)++;
    if (B.at(X)) B.at(Y) = 1;
    if (!V.at(X)) B.at(X) = 0;
  }
  int cnt = 0;
  for (int i = 0; i < N; i++) cnt += V.at(i) && B.at(i);
  cout << cnt << "\n";
}