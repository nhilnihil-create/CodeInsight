#include <bits/stdc++.h>
using namespace std;

int main() {
  string x , y , z ;
  cin >> x >> y >> z ; 
  
  int a = x.size() ;
  int b = y.size() ;
  
  a--; b--;
  
  if(x[a]==y[0] && y[b]==z[0] ) cout << "YES" << endl;
  else cout << "NO" << endl;
}

