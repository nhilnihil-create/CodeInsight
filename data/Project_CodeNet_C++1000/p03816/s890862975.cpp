#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> V(110000, 0);
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    V.at(A)++;
  }
  int K = 0;
  for (int i = 0; i < 110000; i++) {
    if (V.at(i) > 0) K++;
  }
  if (K % 2 == 0) cout << K - 1 << endl;
  else cout << K << endl;
}