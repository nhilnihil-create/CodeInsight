#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string a, b, c;
  cin >> a >> b >> c;
  transform(a.begin(), a.end(), a.begin(), ::toupper);
  transform(b.begin(), b.end(), b.begin(), ::toupper);
  transform(c.begin(), c.end(), c.begin(), ::toupper);
  cout << a.at(0) << b.at(0) << c.at(0);
}

