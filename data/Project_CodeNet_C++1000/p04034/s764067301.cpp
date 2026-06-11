#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> B(N, 1);
  vector<bool> E(N, false);
  E.at(0) = true;
  for (int i = 0; i < M; i++) {
    int X, Y;
    cin >> X >> Y;
    X--;
    Y--;
    B.at(X)--;
    B.at(Y)++;
    if (E.at(X) == true) E.at(Y) = true;
    if (B.at(X) == 0) E.at(X) = false;
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (E.at(i)) ans++;
  }
  cout << ans << endl;
}