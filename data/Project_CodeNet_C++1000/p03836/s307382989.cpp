#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; ++i)
using namespace std;
using ll = long long;

int main() {
  int sx,sy,tx,ty;
  cin >>sx>>sy>>tx>>ty;
  
  int b=tx-sx, a=ty-sy;
  int c=a+1, d=b+1;
  
  rep(i,a) cout << "U";
  rep(i,b) cout << "R";
  rep(i,a) cout << "D";
  rep(i,b) cout << "L";
  cout << "L";
  rep(i,c) cout << "U";
  rep(i,d) cout << "R";
  cout << "D";
  cout << "R";
  rep(i,c) cout << "D";
  rep(i,d) cout << "L";
  cout << "U" << endl;
  return 0;
  
}

