

#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,c,d;
  char b;
  cin >> a >> b >> c;

  // ここにプログラムを追記
  if (b == '+') {
    d = a + c;
  }
  else {
    d = a - c;
  }
  cout << d << endl;
}