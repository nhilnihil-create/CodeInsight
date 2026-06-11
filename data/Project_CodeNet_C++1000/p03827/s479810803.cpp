#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, x = 0, y = 0;
  string S;
  cin >> N >> S;
  for (char c : S) { 
    if (c == 'I') {
      y = max(y,++x);
    } else {
      x--;
    }
  }
  cout << y;
}