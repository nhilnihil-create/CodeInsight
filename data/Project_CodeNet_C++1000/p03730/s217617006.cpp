#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  cout << ((C % gcd(A, B)) ? "NO" : "YES") << "\n";
}