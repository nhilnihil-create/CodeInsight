#include <bits/stdc++.h>
using namespace std;

int main() {
  string a,b,c;
  cin >> a >> b >> c;
  a.at(0)+=(int)'A'-(int)'a';
  b.at(0)+=(int)'A'-(int)'a';
  c.at(0)+=(int)'A'-(int)'a';
  cout << a.at(0) << b.at(0) << c.at(0) << endl;
}