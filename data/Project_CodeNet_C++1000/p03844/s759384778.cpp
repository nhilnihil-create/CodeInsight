#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, c;
  char b;
  cin >> a >> b >> c;
  if (b == '+') a += c;
  else a -= c;
  cout << a;
}