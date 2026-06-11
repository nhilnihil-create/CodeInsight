#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  char c;
  cin >> A >> c >> B;
  if (c == '+') {
    A += B;
  } else if (c == '-') {
    A -= B;
  }
  cout << A << endl;
}