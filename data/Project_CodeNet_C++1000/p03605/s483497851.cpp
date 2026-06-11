#include <bits/stdc++.h>
using namespace std;

int main() {
  string a;
  cin >> a;
  cout << (a.at(0)=='9' || a.at(1) == '9' ? "Yes" : "No") << endl;
}