#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N, M;
  cin >> N >> M;
  vector<int> memo(N);
  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++) {
    cin >> A.at(i) >> B.at(i);
    if (A.at(i) == 1) {
      memo.at(B.at(i) - 1)++;
    }
    if (B.at(i) == 1) {
      memo.at(A.at(i) - 1)++;
    }
  }
  bool ok = false;
  for (int i = 0; i < M; i++) {
    if (A.at(i) == N) {
      if (memo.at(B.at(i) - 1) != 0) {
        ok = true;
        break;
      }
    }
    if (B.at(i) == N) {
      if (memo.at(A.at(i) - 1) != 0) {
        ok = true;
        break;
      }
    }
  }
  if (ok) {
    cout << "POSSIBLE" << endl;
  }
  else {
    cout << "IMPOSSIBLE" << endl;
  }
}