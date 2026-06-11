#include <bits/stdc++.h>
using namespace std;

int mul_3(int x) {
  if(x % 3 == 0) {
    return 1;
  }
  else {
    return 0;
  }
}

int main() {
  int A, B, C;
  cin >> A >> B;
  C = A + B;
  int a, b, c;
  a = mul_3(A);
  b = mul_3(B);
  c = mul_3(C);
  if(a + b + c > 0) {
    cout << "Possible" << endl;
  }
  else {
    cout << "Impossible" << endl;
  }
}
