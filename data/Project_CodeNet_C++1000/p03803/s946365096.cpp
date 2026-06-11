#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  cout << (a == 1 ? (b == 1 ? "Draw" : "Alice") : (b == 1 ? "Bob" : (a == b ? "Draw" : (a > b ? "Alice" : "Bob")))) << endl;
}