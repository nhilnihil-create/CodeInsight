#include <bits/stdc++.h>
using namespace std;

int main() {
  string N, M, O;
  cin >> N >> M >> O;

  char a = N.at(0);
  char b = M.at(0);
  char c = O.at(0);

  int d = (int)a - 32;
  int e = (int)b - 32;
  int f = (int)c - 32;
  cout << (char)d << (char)e << (char)f << endl;
}