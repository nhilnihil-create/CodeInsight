#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int left = b-a;
  int right = c-b;
  cout << ((left == right) ? "YES" : "NO") << "\n";

  return(0);
}