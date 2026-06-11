#include <bits/stdc++.h>
using namespace std;


int main() {

  string a,b,c;
  cin >> a >> b >> c;

  int ax = a.size();
  int bx = b.size();
  int cx = c.size();
  
  string flag = "NO";
  
  if(a.at(ax-1) == b.at(0)){
    if(b.at(bx-1) == c.at(0)){
      flag = "YES";
    }
  }
  
  cout << flag;
}
