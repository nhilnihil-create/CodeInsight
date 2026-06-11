#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X, Y, Z, B;
  cin >> N;
  X = 0;
  B = 0;
  for (int i = 0;i < N;i++){
    cin >> Y >> Z;
    X = Z - Y + 1;
    B = B + X;
  }
    cout << B << endl;
}