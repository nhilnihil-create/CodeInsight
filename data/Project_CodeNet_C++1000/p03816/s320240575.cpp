#include <bits/stdc++.h>
#define M 100001
using namespace std;
int main() {
  int N, A;
  vector<int> B(M), C(3);
  for (cin >> N; N; B[A]++, N--) {
    cin >> A;
  }
  for (int i = 0; i < M; i++) {
    if (B[i] && !(B[i]%2)) {
      C[2]++;
    } else if (B[i]) {
      C[1]++;
    }
  }
  if (C[2]%2) {
    cout << C[2]+C[1]-1;
  } else {
    cout << C[1]+C[2];
  }
}