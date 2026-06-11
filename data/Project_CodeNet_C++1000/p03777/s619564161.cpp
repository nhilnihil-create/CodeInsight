#include <bits/stdc++.h>
using namespace std;

int main() {
  char A, B;
  cin >> A >> B;
  if (A == 'H') return cout << B << "\n", 0;
  else if (B == 'H') return cout << 'D' << "\n", 0;
  else return cout << 'H' << "\n", 0;
}