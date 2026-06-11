#include <bits/stdc++.h>
using namespace std;
int main() {
  int A,B,C;
  cin >> A >> B >> C;
  for (int i = 0; i < B; i++) {
    if ((i*A)%B == C) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}