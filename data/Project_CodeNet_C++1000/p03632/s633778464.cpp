#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int main() {
  
  int a,b,c,d ;
  cin >>a>>b>>c>>d ;

  int l = max(a,c) ;
  int m = min(b,d) ;

  if(l>m) cout << 0 ;
  else cout << m-l ;

  cout << endl ;
  
}