#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  long long int L = -1, S = -1;
  for (int i = 0; i < N - 1; i++) {
    if (A.at(i) == A.at(i + 1) && L == -1) {
      L = A.at(i);
      i++;
    }
    else if (A.at(i) == A.at(i + 1)) {
      S = A.at(i);
      break;
    }
  }
  if (S == -1) cout << 0 << endl;
  else cout << L * S << endl;
}