#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A = 0, B, a, b;
  cin >> N;
  while (cin >> a >> b) if (a > A) A = a, B = b;
  cout << A + B << "\n";
}