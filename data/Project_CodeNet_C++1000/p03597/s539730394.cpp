#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int A;
  int M = 0;

  cin >> N;
  cin >> A;

  if (N < 0 && N > 100 ) {
    exit (1);
  }

  if (N < -1 && N > N * N) {
    exit (1);
  }

  M = N * N - A;

  cout << M << endl;
}

