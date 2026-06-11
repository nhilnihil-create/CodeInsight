#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  
  if (A > B && B >= C && A == B + C) {
    cout << "Yes" << endl;
  } else if (B > A && A >= C && B == A + C) {
    cout << "Yes" << endl;
  } else if (C > A && A >= C && C == A + B) {
    cout << "Yes" << endl;
  } else if (A > C && C >= B && A == B + C) {
    cout << "Yes" << endl;
  } else if (B > C && C >= A && B == A + C) {
    cout << "Yes" << endl;
  } else if (C > B && B >= A && C == A + B) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
