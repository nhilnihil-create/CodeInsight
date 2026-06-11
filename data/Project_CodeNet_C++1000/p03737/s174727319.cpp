#include <bits/stdc++.h>
using namespace std;

char oomozi ( string I ){
  char i;
  char dif = 'A' - 'a';
  i = I.at(0) + dif;
  return i;
}

int main() {
  string a, b, c;
  cin >> a >> b >> c;
  
  cout << oomozi(a) << oomozi(b) << oomozi(c) <<endl;
}