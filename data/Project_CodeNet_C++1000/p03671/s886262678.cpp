#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C, a, b, c;
  cin >> A >> B >> C;
  int X = max(A, B);
  int Y = max(B, C);
  int Z = max(X, Y);
  cout << A + B + C- Z << endl;
}
