#include <bits/stdc++.h>
using namespace std;

int main() {
  int W;
  cin >> W >> W;
  string a, b(W + 2, '#');
  for (cout << b << endl; cin >> a; cout << '#' << a << "#\n");
  cout << b;
}