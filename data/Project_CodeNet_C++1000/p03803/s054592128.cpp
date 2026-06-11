#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  cin >> A >> B;
  if (A != 1 && B != 1) {
    if (A > B) {cout << "Alice" << endl;}
    else if (A == B) {cout << "Draw" << endl;}
    else {cout << "Bob" << endl;}
  }
  else {
    if (A == 1 && B != 1) {cout << "Alice" << endl;}
    else if (A == 1 && B == 1) {cout << "Draw" << endl;}
    else {cout << "Bob" << endl;}
  }
}