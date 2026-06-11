#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  cout << ((A % 3 == 0 || B % 3 == 0 || (A + B) % 3 == 0) ? "Possible" : "Impossible") << "\n";
}