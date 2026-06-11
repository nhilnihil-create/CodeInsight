#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;  
  cin >> N;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  int64_t M = 0, M2 = 0;
  int count = 0;
  for (int i = 0; i < N - 1; i++) {
    if (A.at(i) == A.at(i + 1)) {
      M2 = M;
      M = A.at(i);
      A.at(i + 1) = 1000000001;
      count++;
    }
    if (count == 2) {
      break;
    }
  }
  cout << M2 * M << endl;
}