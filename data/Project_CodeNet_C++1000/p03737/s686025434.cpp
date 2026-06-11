#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string a, b, c ;
  cin >> a >> b >> c;
  char dif = 'A' - 'a';
  
  a.at(0) = a.at(0)+dif;
  b.at(0) = b.at(0)+dif;
  c.at(0) = c.at(0)+dif;
  
  cout << a.at(0) << b.at(0) << c.at(0) << endl; 
  
}