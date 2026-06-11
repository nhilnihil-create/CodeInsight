#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int l = (int) S.find("A");
  int r = (int) S.rfind("Z");
  cout << r - l + 1 << "\n";
}