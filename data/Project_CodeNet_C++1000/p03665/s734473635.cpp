#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, P;
  cin >> N >> P;
  int X = 0;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    if (A % 2 == 1) X++;
  }
  if (X != 0) cout << ((long long int)1 << (N - 1)) << endl;
  else if (P == 1) cout << 0 << endl;
  else cout << ((long long int)1 << N) << endl;
}