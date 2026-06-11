#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  
  if (A <= B && B <= C || B <= A && A <= C) {
    cout << A + B << endl;
  } else if (A <= C && C <= B || C <= A && A <= B) {
    cout << A + C << endl;
  } else if (B <= C && C <= A || C <= B && B <= A) {
    cout << B + C << endl;
  }
}
