#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a;
  d = 0;
  for(int i = 0; i < a; i++) {
    cin >> b;
    cin >> c;
    d += c+1-b;
  }
  cout << d << endl;
}

