#include <bits/stdc++.h>
using namespace std;

int f(unsigned long A, unsigned long B) { return log10(max(A, B)) + 1; }

int main() {
  unsigned long N;
  cin >> N;

  int min_f = INT_MAX;

  for (unsigned long i = 1; i <= sqrt(N); i++) {
    unsigned long A = i;
    if (N % i != 0) continue;
    unsigned long B = N / i;
    min_f = min(min_f, f(A, B));
  }

  cout << min_f << endl;
}