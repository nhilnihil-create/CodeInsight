#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, z;
  int m;
  cin >> x >> y >> z;
  m = x+y;
  if(y+z < m){m = y+z;}
  if(z+x < m){m = z+x;}
  cout << m << endl;
}